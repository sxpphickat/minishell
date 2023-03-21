/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:21:06 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:21:07 by vipereir         ###   ########.fr       */
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
