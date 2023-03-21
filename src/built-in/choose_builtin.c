/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:12 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	my_strncmp(const char *s1, const char *s2)
{
	int		i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_built_in(char *input[])
{
	if (my_strncmp(input[0], "pwd"))
		return (1);
	else if (my_strncmp(input[0], "exit"))
		return (1);
	else if (my_strncmp(input[0], "echo"))
		return (1);
	else if (my_strncmp(input[0], "cd"))
		return (1);
	else if (my_strncmp(input[0], "export"))
		return (1);
	else if (my_strncmp(input[0], "unset"))
		return (1);
	else if (my_strncmp(input[0], "env"))
		return (1);
	return (0);
}

int	ft_choose_builtin(char *input[], t_env *env, t_cmd_list **master_head)
{
	if (my_strncmp(input[0], "pwd"))
		return (ft_pwd());
	else if (my_strncmp(input[0], "exit"))
		ft_exit(input, master_head, env);
	else if (my_strncmp(input[0], "echo"))
		return (ft_echo(input));
	else if (my_strncmp(input[0], "cd"))
		return (cd(input[1], env));
	else if (my_strncmp(input[0], "export"))
		return (ft_export(env, input));
	else if (my_strncmp(input[0], "unset"))
		return (ft_env_unset(env, input));
	else if (my_strncmp(input[0], "env"))
		return (ft_env(env, input));
	return (0);
}

void	exec_builtin(t_cmd_list **cmd_head, t_env *env,
	t_cmd_list **master_head)
{
	int			pid;
	int			fd[2];
	t_cmd_list	*cmd;

	cmd = *cmd_head;
	if (!cmd->does_have_redirect && !cmd->next && !cmd->prev)
	{
		g_ret_value = ft_choose_builtin(cmd->argv, env, master_head);
		return ;
	}
	pipe(fd);
	pid = fork();
	if (!cmd->does_have_redirect)
		cmd->out = fd[1];
	else
		close(fd[1]);
	if (pid == 0)
		exec_fork(env, master_head, cmd, fd);
	else
		exec_else(cmd, fd, pid);
}
