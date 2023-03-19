/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:35:06 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/09 17:16:32 by sxpph            ###   ########.fr       */
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
