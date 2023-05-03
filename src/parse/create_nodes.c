/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:07 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 14:24:47 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_operator(char *op)
{
	if (!op)
		return (0);
	if (!ft_strncmp(op, "|", ft_strlen(op)))
		return (PIPE);
	else if (!ft_strncmp(op, "&&", ft_strlen(op)))
		return (AND);
	else if (!ft_strncmp(op, "||", ft_strlen(op)))
		return (OR);
	else if (!ft_strncmp(op, ">", ft_strlen(op)))
		return (OUTPUT);
	else if (!ft_strncmp(op, "<", ft_strlen(op)))
		return (INPUT);
	else if (!ft_strncmp(op, ">>", ft_strlen(op)))
		return (APPEND);
	else if (!ft_strncmp(op, "<<", ft_strlen(op)))
		return (HERE_DOC);
	return (0);
}

void	create_tokens(char	**splited, t_token	**tokens)
{
	int	i;

	i = 0;
	while (splited[i])
		add_token(tokens, splited[i++]);
}
