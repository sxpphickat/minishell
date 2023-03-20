/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:53:15 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:16 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_a_dir(t_cmd_list	*cmd)
{
	extern int	g_ret_value;

	printf("O_o: %s: is a directory\n", cmd->argv[0]);
	g_ret_value = -126;
	return (-1);
}
