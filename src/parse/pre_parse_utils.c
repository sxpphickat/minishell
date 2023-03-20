/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:56:47 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:56:48 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	quotes_switch(char c, int *status)
{
	if (c == '\'')
	{
		if (*status == S_QUOTE)
			*status = 0;
		else if (*status == 0)
			*status = S_QUOTE;
	}
	if (c == '"')
	{
		if (*status == D_QUOTE)
			*status = 0;
		else if (*status == 0)
			*status = D_QUOTE;
	}
}

void	*syntax_error_free(char *to_free)
{
	extern int	g_ret_value;

	g_ret_value = 258;
	free(to_free);
	ft_putstr_fd("-O_o: syntax error\n", 2);
	return (NULL);
}
