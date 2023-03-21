/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:21:01 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:21:02 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	array_counter(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**matrix_dup(char **mat)
{
	char	**dup;
	int		i;

	i = 0;
	dup = ft_calloc(sizeof(char *), array_counter(mat) + 1);
	while (mat[i])
	{
		dup[i] = ft_strdup(mat[i]);
		i++;
	}
	return (dup);
}
