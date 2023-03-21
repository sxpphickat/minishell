/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:24 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:25 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_pop(t_token **stack_x)
{
	t_token	*temp;

	if ((*stack_x) == NULL)
		return ;
	temp = *stack_x;
	(*stack_x) = temp->next;
	free(temp->word);
	free(temp);
	temp = NULL;
}

int	clear_tokens(t_token **tokens)
{
	while (*tokens)
		ft_pop(tokens);
	return (1);
}
