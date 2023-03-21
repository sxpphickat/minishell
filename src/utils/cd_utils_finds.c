/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_finds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:04 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:05 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_ret_env(t_env *env, char *env_search)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(env_search);
	while (env->env[i])
	{
		if (!ft_strncmp(env->env[i], env_search, len))
			return (i);
		i++;
	}
	return (-1);
}

int	find_pwd(t_env *env)
{
	int	search;

	search = find_ret_env(env, "PWD=");
	if (search != -1)
	{
		free(env->env[search]);
		return (search);
	}
	return (search);
}

int	find_old(t_env *env)
{
	int	search;

	search = find_ret_env(env, "OLDPWD=");
	if (search != -1)
	{
		free(env->env[search]);
		return (search);
	}
	return (search);
}

int	find_home(t_env *env)
{
	int	search;

	search = find_ret_env(env, "HOME=");
	if (search != -1)
		return (search);
	return (search);
}

int	find_oldpwd(t_env *env)
{
	int	search;

	search = find_ret_env(env, "OLDPWD=");
	if (search != -1)
		return (search);
	return (search);
}
