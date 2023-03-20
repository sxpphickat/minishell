/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:03:45 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 18:03:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handler_sigint(int sig)
{
	extern int	g_ret_value;

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
