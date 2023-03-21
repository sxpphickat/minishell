/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:15:14 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:15:15 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	argv_size(t_token **tokens)
{
	t_token	*token;
	int		i;

	token = *tokens;
	i = 0;
	while (token && (token->type == COMMAND || token->type == PARAM))
	{
		i++;
		token = token->next;
	}
	return (i);
}

int	add_redirect(t_redirect_list **r_head, t_token **token, t_cmd_list **c_dad)
{
	int				i;
	t_redirect_list	*redirect_node;

	i = 0;
	redirect_node = add_redirect_node(r_head);
	redirect_node->type = (*token)->type;
	if ((*token)->here_doc_fd)
		redirect_node->here_doc_fd = (*token)->here_doc_fd;
	if (*token && (*token)->is_redirect)
		*token = (*token)->next;
	redirect_node->args = ft_calloc(sizeof(char *), argv_size(token) + 1);
	redirect_node->father_cmd = *c_dad;
	while (*token && ((*token)->type == COMMAND || (*token)->type == PARAM))
	{
		redirect_node->args[i++] = ft_strdup((*token)->word);
		*token = (*token)->next;
	}
	redirect_node->args[i++] = NULL;
	if (*token && (*token)->is_redirect)
		add_redirect(r_head, token, c_dad);
	return (0);
}

void	fill_command(t_cmd_list *cmds, t_token **token)
{
	int	i;

	i = 0;
	if ((*token)->type == PIPE)
		*token = (*token)->next;
	cmds->argv = ft_calloc(sizeof(char *), argv_size(token) + 1);
	while (*token && ((*token)->type == COMMAND || (*token)->type == PARAM))
	{
		cmds->argv[i++] = ft_strdup((*token)->word);
		*token = (*token)->next;
	}
	cmds->argv[i++] = NULL;
}

t_cmd_list	*build_commands(t_token	**tokens)
{
	t_token		*token;
	t_cmd_list	*cmds_head;
	t_cmd_list	*cmds;

	token = *tokens;
	cmds_head = NULL;
	cmds = NULL;
	while (token)
	{
		cmds = add_cmd_node(&cmds_head);
		if (token && token->is_redirect)
		{
			cmds->does_have_redirect = 1;
			add_redirect(&cmds->redirect, &token, &cmds);
		}
		if (token)
			fill_command(cmds, &token);
		if (token && token->is_redirect)
		{
			cmds->does_have_redirect = 1;
			add_redirect(&cmds->redirect, &token, &cmds);
		}
	}
	return (cmds_head);
}
// setar does_have redirect dentro do add_redirect
