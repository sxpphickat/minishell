/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:49:28 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 16:37:48 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_exit(t_env *env, t_cmd_list **master_head)
{
	ft_free_matrix(env->env);
	free(env);
	clear_cmds(master_head);
	clear_history();
}

void	ft_exit(char **input, t_cmd_list **master_head, t_env *env)
{
	int	i;
	int	exit_val;

	i = 0;
	if (!input[1])
	{
		free_exit(env, master_head);
		exit(0);
	}
	while (input[1][i])
	{
		if (input[1][i] >= 0x30 && input[1][i] <= 0x39)
			i++;
		else
		{
			printf("O_o: numeric argument required: %s\n", input[0]);
			free_exit(env, master_head);
			exit(255);
		}
	}
	if (input[2])
		return ((void)printf("O_o: too many arguments: %s\n", input[0]));
	exit_val = ft_atoi(input[1]);
	free_exit(env, master_head);
	exit(exit_val);
}
