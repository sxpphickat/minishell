/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:12:55 by mpolisse          #+#    #+#             */
/*   Updated: 2023/03/21 08:44:08 by rgorki           ###   ########.fr       */
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
