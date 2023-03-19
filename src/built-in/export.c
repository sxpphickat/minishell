/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:41:37 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 16:49:08 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_env_export(t_env *env)
{
	int	i;

	i = 0;
	while (env->env[i])
		printf("declare -x %s\n", env->env[i++]);
}

char	**my_realloc(char **matrix, char *new_str, size_t size, size_t new_size)
{
	char	**new_matrix;
	size_t	i;

	i = 0;
	if (new_size == 0)
		return (free(matrix), NULL);
	if (matrix == NULL)
	{
		new_matrix = ft_calloc(new_size, sizeof(char *));
		if (new_matrix == NULL)
			return (NULL);
		return (new_matrix);
	}
	new_matrix = ft_calloc(new_size, sizeof(char *));
	if (new_matrix == NULL)
		return (NULL);
	while (i < size)
	{
		new_matrix[i] = matrix[i];
		i++;
	}
	new_matrix[i] = ft_strdup(new_str);
	free(matrix);
	return (new_matrix);
}

static void	add_to_matrix(t_env *env, char *new_str)
{
	int	len;

	len = 0;
	len = array_counter(env->env);
	env->env = my_realloc(env->env, new_str, len, len + 2);
}

static int	create_export(t_env *env, char **new_env, int i, int flag)
{
	int		search;
	char	*temp;

	temp = search_delimiter(new_env[i]);
	search = find_env_exp(env, temp);
	if (flag != 1 && check_export(new_env[i]) == -1)
			flag = 1;
	else if (check_export(new_env[i]) != -1 && search == -1
		&& ft_strchr(new_env[i], '='))
		add_to_matrix(env, new_env[i]);
	else if (check_export(new_env[i]) != -1 && ft_strchr(new_env[i], '='))
	{
		free(env->env[search]);
		env->env[search] = ft_strdup(new_env[i]);
	}
	free(temp);
	return (flag);
}

int	ft_export(t_env *env, char **new_env)
{
	int	i;
	int	flag;
	int	is_null;

	i = 1;
	flag = 0;
	is_null = 1;
	if (array_counter(new_env) == 1)
	{
		ft_env_export(env);
		return (flag);
	}
	while (new_env[i])
	{
		if (new_env[i][0] != 0)
			is_null = 0;
		i++;
	}
	i = 1;
	while (new_env[i])
		flag = create_export(env, new_env, i++, flag);
	if (is_null == 1)
		ft_env_export(env);
	return (flag);
}
