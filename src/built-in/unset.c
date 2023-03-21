/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:14:54 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 09:42:29 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**my_realloc_create(char **matrix,
	char **new_matrix, size_t env_location, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (i == env_location)
		{
			free(matrix[i]);
			i++;
		}
		new_matrix[j++] = matrix[i++];
	}
	return (new_matrix);
}

static char	**my_realloc_unset(char **matrix, size_t env_location,
	size_t size, size_t new_size)
{
	char	**new_matrix;

	if (new_size == 0)
	{
		free(matrix);
		return (NULL);
	}
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
	new_matrix = my_realloc_create(matrix, new_matrix, env_location, size);
	free(matrix);
	return (new_matrix);
}

static int	find_env_unset(t_env *env, char *env_search)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(env_search, "=");
	i = find_env(env, temp);
	if (env->env[i] != NULL)
	{
		free(temp);
		return (i);
	}
	free(temp);
	return (-1);
}

static void	env_unset_mod(t_env *env, char **input, int k)
{
	int		env_location;
	size_t	len;

	len = array_counter(env->env);
	env_location = find_env_unset(env, input[k]);
	if (env_location != -1)
		env->env = my_realloc_unset(env->env, env_location, len, len);
}

int	ft_env_unset(t_env *env, char **input)
{
	int	k;
	int	count;

	k = 1;
	count = array_counter(input) - 1;
	if (count == 0)
		return (0);
	while (count)
	{
		if (check_unset(input[k]) != -1)
			if (find_env_unset(env, input[k]) != -1)
				env_unset_mod(env, input, k);
		count--;
		k++;
	}
	return (0);
}
