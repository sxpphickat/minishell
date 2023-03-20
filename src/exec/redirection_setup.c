/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:53:32 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:33 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_here_doc(t_redirect_list **redirect)
{
	(*redirect)->father_cmd->in = (*redirect)->here_doc_fd;
}

int	set_input(t_redirect_list **redirect)
{
	int	in;

	in = open((*redirect)->args[0], O_RDONLY);
	if (in == -1)
	{
		printf("O_o: %s: No such file or directory\n", (*redirect)->args[0]);
		return (-1);
	}
	(*redirect)->father_cmd->in = in;
	return (0);
}

void	set_out_put_append(t_redirect_list **redirect)
{
	int	mode;

	mode = 0;
	if ((*redirect)->type == OUTPUT)
		mode = O_TRUNC;
	else if ((*redirect)->type == APPEND)
		mode = O_APPEND;
	(*redirect)->father_cmd->out = open((*redirect)->args[0], O_RDWR | O_CREAT
			| mode, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

int	redirection_setup(t_redirect_list **redirect_head, t_cmd_list **cmd)
{
	extern int		g_ret_value;
	t_redirect_list	*redirect;

	redirect = *redirect_head;
	while (redirect)
	{
		if ((redirect)->type == INPUT)
		{
			if (set_input(&redirect) == -1)
			{
				(*cmd) = (*cmd)->next;
				g_ret_value = 1;
				return (-1);
			}
		}
		if ((redirect)->type == HERE_DOC)
			set_here_doc(&redirect);
		if ((redirect)->type == OUTPUT || (redirect)->type == APPEND)
			set_out_put_append(&redirect);
		(redirect) = (redirect)->next;
	}
	return (0);
}
