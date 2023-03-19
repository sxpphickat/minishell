/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:03:31 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/11 14:31:47 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	command_not_found(t_cmd_list	*cmd)
{
	extern int	g_ret_value;

	printf("O_o: command not found: %s\n", cmd->argv[0]);
	g_ret_value = -127;
	return (-1);
}
