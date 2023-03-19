/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:14:10 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/11 14:32:54 by sxpph            ###   ########.fr       */
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
