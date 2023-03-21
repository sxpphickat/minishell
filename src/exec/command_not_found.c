/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:03:31 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/21 08:38:43 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	command_not_found(t_cmd_list	*cmd)
{
	printf("O_o: command not found: %s\n", cmd->argv[0]);
	g_ret_value = -127;
	return (-1);
}
