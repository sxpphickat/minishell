/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:15:33 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:15:34 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	command_not_found(t_cmd_list	*cmd)
{
	printf("O_o: command not found: %s\n", cmd->argv[0]);
	g_ret_value = -127;
	return (-1);
}
