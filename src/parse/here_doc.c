/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:30 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:18:31 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_here_doc(t_token **tokens)
{
	t_token	*token;

	token = *tokens;
	if (!token->word[0])
		return (-1);
	while (token)
	{
		if (token->type == HERE_DOC)
		{
			if (ft_here_doc(token->next->word, token))
				return (-1);
			token = token->next;
		}
		token = token->next;
	}
	return (0);
}

int	ft_here_doc(char *delimiter, t_token *token)
{
	int			fd[2];
	char		*read;

	pipe(fd);
	g_ret_value = 0;
	read = readline("heredoc> ");
	if (g_ret_value == 1)
		return (close(fd[0]), close(fd[1]), return_free(read, -1));
	while (read && (my_strncmp(read, delimiter) == 0))
	{
		if (g_ret_value == 1)
			return (close(fd[0]), close(fd[1]), return_free(read, -1));
		if (!my_strncmp(read, delimiter))
		{
			ft_putstr_fd(read, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
		free(read);
		read = readline("heredoc> ");
	}
	free(read);
	close(fd[1]);
	token->here_doc_fd = fd[0];
	return (0);
}
