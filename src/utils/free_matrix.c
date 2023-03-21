/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:48 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:20:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (1);
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (1);
}
