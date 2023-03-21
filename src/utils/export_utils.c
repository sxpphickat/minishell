/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:35 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:36 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*search_delimiter(char *s1)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = ft_strdup(s1);
	if (!s1)
		return (NULL);
	while (s1[i] && s1[i] != '=')
		i++;
	if (s1[i] == '=')
	{
		while (j <= i)
		{
			temp[j] = s1[j];
			j++;
		}
		temp[j] = '\0';
		return (temp);
	}
	return (temp);
}

int	return_free(void *to_free, int to_return)
{
	free(to_free);
	return (to_return);
}

int	find_errors_export(char *new_env)
{
	int		i;
	char	*temp;

	i = 0;
	temp = search_delimiter(new_env);
	if (!temp)
		return (return_free(temp, 0));
	if (temp[0] == '=' || ft_isdigit(temp[0]))
		return (return_free(temp, 1));
	while (temp[i])
	{
		if (temp[i] == 33 || temp[i] == 35 || temp[i] == 37
			|| (temp[i] >= 40 && temp[i] <= 47) || temp[i] == 60
			|| temp[i] == 58 || (temp[i] >= 62 && temp[i] <= 64)
			|| (temp[i] >= 91 && temp[i] <= 94)
			|| (temp[i] >= 123 && temp[i] < 127))
		{
			free(temp);
			return (1);
		}
		i++;
	}
	free(temp);
	return (0);
}

int	check_export(char *new_env)
{
	if (find_errors_export(new_env))
	{
		printf("export: '%s': not a valid identifier\n", new_env);
		return (-1);
	}
	if (!ft_strchr(new_env, '='))
		return (0);
	return (0);
}

int	find_env_exp(t_env *env, char *env_search)
{
	int	i;
	int	len;

	i = 0;
	if (!env_search)
		return (0);
	len = ft_strlen(env_search);
	while (env->env[i])
	{
		if (!ft_strncmp(env->env[i], env_search, len))
			return (i);
		i++;
	}
	return (-1);
}
