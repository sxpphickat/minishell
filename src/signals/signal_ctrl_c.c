/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:31 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:32 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handler_sigint(int sig)
{
	(void)sig;
	if (RL_ISSTATE(RL_STATE_READCMD))
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	else
		printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_ret_value = 1;
}

int	jump_line(void)
{
	signal(SIGINT, handler_sigint);
	return (0);
}
