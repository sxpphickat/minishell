/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:44:04 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/13 12:13:42 by vipereir         ###   ########.fr       */
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
