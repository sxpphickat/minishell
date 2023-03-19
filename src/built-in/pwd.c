/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:49:19 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 16:16:52 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_pwd(char *temp, char *buff)
{
	free(temp);
	free(buff);
}

static char	*pwd_util(char *buff, int size)
{
	while (!getcwd(buff, size))
	{
		free(buff);
		size++;
		buff = malloc(sizeof(char) * size);
	}
	return (buff);
}

int	ft_pwd(void)
{
	char	*buff;
	char	*temp;
	int		size;

	size = 1;
	buff = malloc(sizeof(char) * size);
	if (!buff)
		return (0);
	temp = getcwd(NULL, 0);
	if (!temp)
	{
		free_pwd(temp, buff);
		printf("cd: error retrieving current directory: ");
		printf("getcwd: cannot access parent directories:");
		printf("No such file, directory\n");
		return (0);
	}
	else
		buff = pwd_util(buff, size);
	printf("%s\n", buff);
	free_pwd(temp, buff);
	return (0);
}
