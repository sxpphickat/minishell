/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:26 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:27 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	log_out_interface(char *read, t_env *env)
{
	if (read == NULL)
	{
		free(read);
		ft_free_matrix(env->env);
		free(env);
		clear_history();
		printf("\x1b[1A\033[3C exit\n");
		exit(0);
	}
}
