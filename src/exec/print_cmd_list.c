/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:53:23 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:24 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_cmd_list(t_cmd_list	*cmds)
{
	while (cmds)
	{
		printf("\n--------------------------\n");
		printf("argv: \n\n");
		print_matrix(cmds->argv);
		while (cmds->redirect)
		{
			printf("    ");
			printf("%i\n", cmds->redirect->type);
			printf("    ");
			print_matrix(cmds->redirect->args);
			cmds->redirect = cmds->redirect->next;
		}
		printf("\n--------------------------\n");
		cmds = cmds->next;
	}
}
