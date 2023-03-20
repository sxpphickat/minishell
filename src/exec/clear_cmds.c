/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:52:22 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:52:23 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pop_cmd(t_cmd_list **cmd_head)
{
	t_cmd_list	*cmd;

	cmd = (*cmd_head);
	(*cmd_head) = (*cmd_head)->next;
	if ((*cmd_head))
		(*cmd_head)->prev = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	while (cmd->redirect)
		pop_redirect(&cmd->redirect);
	cmd->redirect = NULL;
	ft_free_matrix(cmd->argv);
	free(cmd);
}

void	pop_redirect(t_redirect_list **redirect_head)
{
	t_redirect_list	*redirect;

	redirect = *redirect_head;
	(*redirect_head) = (*redirect_head)->next;
	if ((*redirect_head))
		(*redirect_head)->prev = NULL;
	redirect->father_cmd = NULL;
	redirect->prev = NULL;
	redirect->next = NULL;
	ft_free_matrix(redirect->args);
	free(redirect);
}

void	clear_cmds(t_cmd_list	**cmd_head)
{
	t_cmd_list	*cmds;

	cmds = *cmd_head;
	while (cmds)
		pop_cmd(&cmds);
}
