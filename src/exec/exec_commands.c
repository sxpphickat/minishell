/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:52:51 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:52:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	dup_in(t_cmd_list **cmds_head)
{
	t_cmd_list	*cmds;

	cmds = *cmds_head;
	while (cmds)
	{
		cmds->in = dup(0);
		cmds = cmds->next;
	}
}

void	exec_commands(t_cmd_list **cmds_head, t_env *env)
{
	t_cmd_list	*cmds;

	dup_in(cmds_head);
	cmds = *cmds_head;
	while (cmds)
	{
		if (cmds->does_have_redirect)
			if (redirection_setup(&cmds->redirect, &cmds) == -1)
				continue ;
		if (cmds->argv)
			exec_cmd(&cmds, env);
		cmds = cmds->next;
	}
	wait_pids(*cmds_head);
}
// acho q n preciso mais dessas checagens de first redirect;
// se der erro ir para o proximo pipe;
