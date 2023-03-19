/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:13:25 by vipereir          #+#    #+#             */
/*   Updated: 2023/02/14 14:57:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_cmds(t_token **list)
{
	int			i;
	t_token		*tokens_list;

	tokens_list = *list;
	i = 1;
	printf("\nprint_cmds\n");
	while (tokens_list)
	{
		printf("cmd[%i] type: %i\n", i, tokens_list->type);
		printf("word: %s\n", tokens_list->word);
		i++;
		tokens_list = tokens_list->next;
	}
	printf("\n");
}
