/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:38 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:16:39 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_exit_status(int exit_status)
{
	if (g_ret_value < 0)
	{
		g_ret_value *= -1;
		return ;
	}
	if (WIFEXITED(exit_status))
		g_ret_value = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		g_ret_value = 128 + WTERMSIG(exit_status);
}
