/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:17:19 by sxpph             #+#    #+#             */
/*   Updated: 2023/03/12 12:57:55 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_matrix(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	check_dir(char	*path)
{
	DIR	*check;

	check = opendir(path);
	if (check == NULL)
		return (1);
	closedir(check);
	return (0);
}
