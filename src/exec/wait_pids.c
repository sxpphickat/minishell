/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:44 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 12:24:54 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	wait_pids(t_cmd_list *cmds)
{
	int	status;

	status = 0;
	while (cmds)
	{
		waitpid(cmds->pid, &status, 0);
		set_exit_status(status);
		cmds = cmds->next;
	}
}

void	wait_single_pid(t_cmd_list *cmds)
{
	int	status;

	status = 0;
	waitpid(cmds->pid, &status, 0);
	set_exit_status(status);
}
