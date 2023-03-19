/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:39:36 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/16 08:44:36 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execer(t_token **tokens, t_env *env)
{
	t_cmd_list	*cmds;
	t_cmd_list	*cmds_head;

	cmds = build_commands(tokens);
	cmds_head = cmds;
	clear_tokens(tokens);
	exec_commands(&cmds, env);
	clear_cmds(&cmds_head);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
