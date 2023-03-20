/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:52:32 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:52:33 by vipereir         ###   ########.fr       */
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
