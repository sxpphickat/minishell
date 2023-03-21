/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_builtins_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:16 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:17 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_fork(t_env *env, t_cmd_list **master_head,
	t_cmd_list	*cmd, int *fd)
{
	signal(SIGQUIT, SIG_DFL);
	close(fd[0]);
	dup2(cmd->in, 0);
	close(cmd->in);
	if (cmd->next || cmd->does_have_redirect)
	{
		dup2(cmd->out, 1);
		close(cmd->out);
	}
	exit(ft_choose_builtin(cmd->argv, env, master_head));
}

void	exec_else(t_cmd_list	*cmd, int *fd, int pid)
{
	close(fd[1]);
	close(cmd->in);
	if (cmd->next)
		cmd->next->in = fd[0];
	cmd->pid = pid;
}
