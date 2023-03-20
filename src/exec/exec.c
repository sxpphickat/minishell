/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:53:07 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:08 by vipereir         ###   ########.fr       */
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
