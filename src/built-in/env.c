/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:29 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_env *env, char **input)
{
	int	i;

	i = 0;
	if (array_counter(input) != 1)
	{
		printf("only env with no options or arguments\n");
		return (-127);
	}
	while (env->env[i])
		printf("%s\n", env->env[i++]);
	return (0);
}
