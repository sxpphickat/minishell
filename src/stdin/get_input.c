/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:50 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:51 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_input(t_env *env)
{
	char	*read;

	read = readline("O_o ");
	log_out_interface(read, env);
	if (ft_strncmp(read, "", 1) != 0)
		add_history(read);
	return (read);
}
