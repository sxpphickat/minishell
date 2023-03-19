/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:29:54 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 19:23:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_charjoin(char const *s1, char const	c)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
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

	i = 0;
	word = (*tokens)->word;
	new_word = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	while (word[i])
	{
		if (word[i] && word[i] == '\'' && word[i + 1]
			&& have_quotes(&word[i + 1]) == '\'')
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
