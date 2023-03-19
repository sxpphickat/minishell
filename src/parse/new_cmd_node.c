/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:59 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 09:13:18 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_token(t_token **head, char *word)
{
	t_token	*new_token;
	t_token	*temp;

	temp = (*head);
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->word = ft_strdup(word);
	new_token->type = 0;
	new_token->next = NULL;
	if (*head == NULL)
	{
		*head = new_token;
		new_token->prev = NULL;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_token;
	new_token->prev = temp;
}

void	add_here_doc_token(t_token **head, char *word)
{
	t_token	*new_token;
	t_token	*temp;

	temp = (*head);
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->word = ft_strdup(word);
	new_token->type = 0;
	new_token->next = NULL;
	if (*head == NULL)
	{
		*head = new_token;
		new_token->prev = NULL;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_token;
	new_token->prev = temp;
}
