/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:15:45 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 15:02:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dup_close(int in, int out)
{
	dup2(out, 1);
	close(out);
	dup2(in, 0);
	close(in);
}

void	exec_to_pipe(t_cmd_list **cmd_head, t_env *env)
{
	int			fd[2];
	int			pid;
	t_cmd_list	*cmd;

	cmd = *cmd_head;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		close(fd[0]);
		if (cmd->out == 1 && cmd->logic_operator == 0)
			cmd->out = fd[1];
		if (cmd->out == 1 && cmd->logic_operator)
			cmd->out = dup(STDOUT_FILENO);
		dup_close(cmd->in, cmd->out);
		execve(cmd->argv[0], cmd->argv, env->env);
	}
	else
	{
		close(fd[1]);
		close(cmd->in);
		cmd->next->in = fd[0];
		cmd->pid = pid;
	}
}

void	exec_last(t_cmd_list **cmd_head, t_env *env)
{
	int			pid;
	t_cmd_list	*cmd;

	cmd = *cmd_head;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(cmd->in, 0);
		close(cmd->in);
		dup2(cmd->out, 1);
		if (cmd->out != 1)
			close(cmd->out);
		execve(cmd->argv[0], cmd->argv, env->env);
	}
	else
	{
		close(cmd->in);
		cmd->pid = pid;
	}
}

void	exec_cmd(t_cmd_list **cmd_head, t_env *env)
{
	t_cmd_list	*cmd;

	cmd = *cmd_head;
	if (check_built_in(cmd->argv))
		return (exec_builtin(&cmd, env, cmd_head));
	cmd->argv[0] = find_path(cmd->argv[0], env);
	if (access(cmd->argv[0], F_OK) == 0 && access(cmd->argv[0], X_OK))
	{
		printf("O_o: Permission denied: %s\n", cmd->argv[0]);
		g_ret_value = -126;
	}
	else if (access(cmd->argv[0], F_OK))
		return ((void)command_not_found(cmd));
	if (!check_dir(cmd->argv[0]))
		return ((void)is_a_dir(cmd));
	if (cmd->next)
		exec_to_pipe(&cmd, env);
	else
		exec_last(&cmd, env);
}
