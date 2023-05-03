/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:53 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 14:06:11 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_spaces(char *s, int i, int op, int direction)
{
	char	comp;

	comp = 0;
	if (op == PIPE)
		comp = '|';
	if (op == INPUT)
		comp = '<';
	if (op == OUTPUT)
		comp = '>';
	if ((s[i] == comp && s[i + direction] != ' ' && s[i + direction] != comp))
		return (1);
	return (0);
}

static int	new_len(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (check_spaces(s, i, PIPE, 1) || check_spaces(s, i, OUTPUT, 1)
			|| check_spaces(s, i, INPUT, 1))
			len++;
		if (i >= 1)
			if (check_spaces(s, i, PIPE, -1) || check_spaces(s, i, OUTPUT, -1)
				|| check_spaces(s, i, INPUT, -1))
				len++;
		i++;
		len++;
	}
	return (len);
}

static int	check_pipe(char *str, int i)
{
	if (str[i] == '|' && str[i + 1] == '|')
		return (0);
	if ((str[i] != ' ' && str[i + 1] == '|')
		|| (str[i] == '|' && str[i + 1] != ' '))
		return (1);
	return (0);
}

static int	check_in_out_redirect(char *str, int i)
{
	if ((str[i] != ' ' && str[i] != '>' && str[i + 1] == '>')
		|| (str[i] == '>' && str[i + 1] != ' ' && str[i + 1] != '>'))
		return (1);
	if ((str[i] != ' ' && str[i] != '<' && str[i + 1] == '<')
		|| (str[i] == '<' && str[i + 1] != ' ' && str[i + 1] != '<'))
		return (1);
	return (0);
}

char	*pre_parse(char *str)
{
	char	*new_read;
	int		i;
	int		j;
	int		status;

	status = 0;
	i = 0;
	j = 0;
	new_read = ft_calloc(sizeof(char), new_len(str) + 1);
	while (str[i])
	{
		quotes_switch(str[i], &status);
		new_read[j] = str[i];
		if (status == 0 && (check_pipe(str, i)
				|| check_in_out_redirect(str, i)))
			new_read[++j] = ' ';
		j++;
		i++;
	}
	if (status != 0)
		return (syntax_error_free(new_read));
	new_read[j] = '\0';
	check_empty_quotes(new_read);
	return (new_read);
}
