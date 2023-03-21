/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:13:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:13:28 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_oldpwd(t_env *env)
{
	char	**input;

	if (find_oldpwd(env) != -1)
	{
		input = ft_calloc(sizeof(char *), 3);
		if (!input)
			return ;
		input[0] = ft_strdup("export");
		input[1] = ft_strdup("OLDPWD=");
		ft_export(env, input);
		ft_free_matrix(input);
	}
}

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
	init_oldpwd(env);
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
