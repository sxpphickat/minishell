/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:06 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:07 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_type(t_token	**tokens)
{
	t_token	*token;
	int		status;

	status = 0;
	token = *tokens;
	while (token)
	{
		if (is_operator(token->word))
		{
			token->type = is_operator(token->word);
			if (token->type != PIPE)
				token->is_redirect = 1;
			status = 0;
		}
		else if (status == 0)
		{
			token->type = COMMAND;
			status = 1;
		}
		else
			token->type = PARAM;
		token = token->next;
	}
}
