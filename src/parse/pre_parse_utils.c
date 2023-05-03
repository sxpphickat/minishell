/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:49 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 13:46:08 by vipereir         ###   ########.fr       */
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

void	dquotes_switch(char c, int *status)
{
	if (c && c == '"')
	{
		if (*status == D_QUOTE)
			*status = 0;
		else if (*status == 0)
			*status = D_QUOTE;
	}
}

void	*syntax_error_free(char *to_free)
{
	g_ret_value = 258;
	free(to_free);
	ft_putstr_fd("-O_o: syntax error\n", 2);
	return (NULL);
}

void	check_empty_quotes(char *new_read)
{
	if (ft_strlen(new_read) == 2
		&& ((new_read[0] == '"' && new_read[1] == '"')
			|| (new_read[0] == 39 && new_read[1] == 39)))
		printf("O_o : command not found:\n");
}
