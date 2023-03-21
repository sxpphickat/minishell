/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:49:33 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 16:32:35 by rgorki           ###   ########.fr       */
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
