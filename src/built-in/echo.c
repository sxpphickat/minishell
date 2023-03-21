/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:20 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:21 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(char	**input)
{
	int	i;

	i = 1;
	if (!input[1])
	{
		printf("\n");
		return (0);
	}
	if (!ft_strncmp(input[1], "-n", ft_strlen("-n")))
		i++;
	while (input[i])
	{
		printf("%s", input[i]);
		if (input[i + 1])
			printf(" ");
		i++;
	}
	if (ft_strncmp(input[1], "-n", ft_strlen("-n")))
		printf("\n");
	return (0);
}
