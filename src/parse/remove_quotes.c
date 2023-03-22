/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:59 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/22 12:37:40 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	have_quotes(char	*word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '"' || word[i] == '\'')
			return (word[i]);
		i++;
	}
	return ('\0');
}

char	have_dquotes(char	*word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] && word[i] == '\'')
			return (word[i]);
		i++;
	}
	return ('\0');
}

static void	split_quotes(t_token	**tokens, char quote_type)
{
	t_token	*token;
	char	*new_word;
	char	**splited;
	int		i;

	i = 0;
	token = *tokens;
	new_word = NULL;
	splited = ft_split(token->word, quote_type);
	if (!splited[0])
		new_word = ft_strdup("");
	else
		new_word = ft_strdup(splited[i++]);
	while (splited[i])
		new_word = ft_gnl_strjoin(new_word, splited[i++]);
	ft_free_matrix(splited);
	free(token->word);
	token->word = new_word;
}

void	remove_quotes(t_token	**tokens)
{
	t_token	*token;
	char	quote_type;

	quote_type = '\0';
	token = *tokens;
	while (token)
	{
		quote_type = have_quotes(token->word);
		if (quote_type)
			split_quotes(&token, quote_type);
		token = token->next;
	}
}
