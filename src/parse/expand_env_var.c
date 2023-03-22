/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:16 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/22 12:38:06 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_charjoin(char const *s1, char const	c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !c)
		return (NULL);
	str = (char *)malloc(ft_gnl_strlen(s1) + 1 + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

void	replace_word(t_token **tokens, char *new_word)
{
	free((*tokens)->word);
	(*tokens)->word = new_word;
}

void	word_expanssion(t_token **tokens, t_env *env)
{
	char		*word;
	char		*new_word;
	int			i;
	int			quote_flag;

	quote_flag = 0;
	i = 0;
	word = (*tokens)->word;
	new_word = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	while (word[i])
	{
		if (word[i] && word[i] == '"')
			dquotes_switch(word[i], &quote_flag);
		if (word[i] && word[i] == '\'' && word[i + 1]
			&& have_dquotes(&word[i + 1]) == '\'' && quote_flag == 0)
			new_word = single_quotes_jump(word, new_word, &i);
		if (word[i] && word[i] == '$' && word[i + 1] == '?')
			new_word = expand_ret_val_case(new_word, &i);
		else if (word[i] && word[i] == '$' && ft_isalnum(word[i + 1]))
			new_word = expand_env_case(word, new_word, &i, env);
		else if (word[i])
			new_word = ft_charjoin(new_word, word[i++]);
	}
	replace_word(tokens, new_word);
}

void	expand_env_var(t_token **tokens, t_env *env)
{
	t_token	*token;

	token = *tokens;
	while (token != NULL)
	{
		word_expanssion(&token, env);
		token = token->next;
	}
}
