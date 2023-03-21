/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:01:26 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/08 17:44:41 by sxpph            ###   ########.fr       */
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
