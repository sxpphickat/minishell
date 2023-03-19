/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:25:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:02 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*find_var_in_word(char *word)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (word[i] && word[i] == '$')
		i++;
	j = i;
	while (word[i] && ft_isalnum(word[i]))
		i++;
	return (ft_substr(word, j, i - j));
}

char	*expand_env_case(char *word, char *new_word, int *i, t_env *env)
{
	char	*to_find;

	to_find = find_var_in_word(&word[*i]);
	if (env->env[find_env(env, to_find)])
		new_word = ft_gnl_strjoin(new_word,
				ft_strchr(env->env[find_env(env, to_find)], '=') + 1);
	else
		new_word = ft_gnl_strjoin(new_word, "");
	*i += ft_strlen(to_find) + 1;
	free(to_find);
	return (new_word);
}

char	*expand_ret_val_case(char *new_word, int *i)
{
	char		*ret_val;
	extern int	g_ret_value;

	ret_val = ft_itoa(g_ret_value);
	new_word = ft_gnl_strjoin(new_word, ret_val);
	free(ret_val);
	*i += 2;
	return (new_word);
}

char	*single_quotes_jump(char *word, char *new_word, int *i)
{
	new_word = ft_charjoin(new_word, word[(*i)++]);
	while (word[*i] && word[*i] != '\'')
		new_word = ft_charjoin(new_word, word[(*i)++]);
	if (word[*i] && word[*i] == '\'')
		new_word = ft_charjoin(new_word, word[(*i)++]);
	return (new_word);
}
