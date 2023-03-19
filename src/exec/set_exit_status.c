/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:27:54 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/12 14:12:58 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_exit_status(int exit_status)
{
	extern int	g_ret_value;

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
