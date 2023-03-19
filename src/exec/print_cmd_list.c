/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:11:33 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/12 14:12:49 by sxpph            ###   ########.fr       */
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
