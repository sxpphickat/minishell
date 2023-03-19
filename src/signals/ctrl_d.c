/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:57:04 by mpolisse          #+#    #+#             */
/*   Updated: 2023/03/13 12:17:16 by vipereir         ###   ########.fr       */
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
