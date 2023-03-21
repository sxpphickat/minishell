/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:12 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	return_syntax_error(void)
{
	g_ret_value = 258;
	ft_putstr_fd("-O_o: syntax error\n", 2);
	return (1);
}

int	syntax_checker(t_token	**tokens)
{
	t_token	*token;

	token = *tokens;
	if (token->type == PIPE)
		return (return_syntax_error());
	while (token->next)
	{
		if ((token->type != COMMAND && token->type != PARAM)
			&& (token->next->type != COMMAND && token->next->type != PARAM))
			return (return_syntax_error());
		token = token->next;
	}
	if (token->type != COMMAND && token->type != PARAM)
		return (return_syntax_error());
	return (0);
}
