/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:21:10 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:21:11 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_errors_unset(char *new_env)
{
	int		i;

	i = 0;
	if (new_env[0] == '=' || ft_isdigit(new_env[0]))
		return (1);
	while (new_env[i])
	{
		if (new_env[i] == 33 || new_env[i] == 35 || new_env[i] == 37
			|| (new_env[i] >= 40 && new_env[i] <= 47) || new_env[i] == 60
			|| new_env[i] == 58 || (new_env[i] >= 62 && new_env[i] <= 64)
			|| (new_env[i] >= 91 && new_env[i] <= 94) || new_env[i] == '='
			|| (new_env[i] >= 123 && new_env[i] < 127))
			return (1);
		i++;
	}
	return (0);
}

int	check_unset(char *new_env)
{
	if (find_errors_unset(new_env))
	{
		printf("unset: '%s': not a valid identifier\n", new_env);
		return (-1);
	}
	if (!ft_strchr(new_env, '='))
		return (0);
	return (0);
}
