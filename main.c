/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:32:26 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/19 14:28:32 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_ret_value;

int	main(int argc, char *argv[], char **envp)
{
	t_env		*env;
	char		*input;
	t_token		*tokens;

	(void)argv;
	if (argc != 1)
		return (0);
	tokens = NULL;
	env = malloc(sizeof(t_env));
	env->env = matrix_dup(envp);
	signal(SIGQUIT, SIG_IGN);
	jump_line();
	while (666)
	{
		input = get_input(env);
		if (parse(input, &tokens, env))
			continue ;
		execer(&tokens, env);
	}
	clear_history();
	ft_free_matrix(env->env);
	free(env);
	return (0);
}
