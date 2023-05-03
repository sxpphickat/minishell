/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:51 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 11:58:05 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_oldpwd(t_env *env)
{
	char	**input;

	if (find_oldpwd(env) != -1)
	{
		input = ft_calloc(sizeof(char *), 3);
		if (!input)
			return ;
		input[0] = ft_strdup("export");
		input[1] = ft_strdup("OLDPWD=");
		ft_export(env, input);
		ft_free_matrix(input);
	}
}

static void	free_pwd(char *temp, char *buff)
{
	free(temp);
	free(buff);
}

char	*pwd_util(char *buff, int size)
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
