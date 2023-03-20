/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:56:29 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:56:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (j != i)
			k++;
	}
	return (k);
}

static void	*clear_word(char **temp_s)
{
	int	i;

	i = 0;
	while (temp_s[i] != NULL)
	{
		free(temp_s[i]);
		i++;
	}
	free(temp_s);
	return (temp_s = NULL);
}

static void	initialize_var_parse_spit(int	*i, int *j, int *k, int *status)
{
	*status = 0;
	*i = 0;
	*k = 0;
	*j = 0;
}

char	**parse_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		status;
	char	**temp_s;

	initialize_var_parse_spit(&i, &j, &k, &status);
	if (!s)
		return (NULL);
	temp_s = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!temp_s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && (s[i] != c || status != 0))
			quotes_switch(s[i++], &status);
		if (j != i)
			temp_s[k++] = ft_substr(s, j, i - j);
		if (k > 0 && temp_s[k - 1] == NULL && count_word(s, c) > 0)
			return (clear_word(temp_s));
	}
	return (temp_s);
}
