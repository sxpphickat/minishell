/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:15:05 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 14:48:31 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	set_cmd_node_value(t_cmd_list *new_node)
{
	new_node->argv = NULL;
	new_node->in = 0;
	new_node->out = 1;
	new_node->pid = 0;
	new_node->logic_operator = 0;
	new_node->does_have_redirect = 0;
	new_node->redirect = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
}

t_cmd_list	*add_cmd_node(t_cmd_list **cmds_head)
{
	t_cmd_list	*new_node;
	t_cmd_list	*temp;

	temp = (*cmds_head);
	new_node = ft_calloc(sizeof(t_cmd_list), 1);
	set_cmd_node_value(new_node);
	if (*cmds_head == NULL)
	{
		*cmds_head = new_node;
		new_node->prev = NULL;
		return (new_node);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}

static void	set_redirect_node_value(t_redirect_list *new_node)
{
	new_node->type = 0;
	new_node->args = NULL;
	new_node->father_cmd = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
}

t_redirect_list	*add_redirect_node(t_redirect_list **redirect_head)
{
	t_redirect_list	*new_node;
	t_redirect_list	*temp;

	temp = (*redirect_head);
	new_node = ft_calloc(sizeof(t_redirect_list), 1);
	set_redirect_node_value(new_node);
	if (*redirect_head == NULL)
	{
		*redirect_head = new_node;
		new_node->prev = NULL;
		return (new_node);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}
