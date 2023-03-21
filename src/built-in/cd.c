/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:14:03 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	att_env(t_env *env, char *save_pwd, char *cd_result)
{
	int		ret_old;
	int		ret_pwd;
	char	*temp_pwd;

	temp_pwd = NULL;
	ret_old = find_old(env);
	ret_pwd = find_pwd(env);
	if (ret_old != -1)
	{
		temp_pwd = ft_strdup(save_pwd);
		env->env[ret_old] = ft_strjoin("OLDPWD=", temp_pwd);
		free(temp_pwd);
	}
	if (ret_pwd != -1)
		env->env[ret_pwd] = ft_strjoin("PWD=", cd_result);
}

static char	*get_pwd(void)
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
		free(temp);
		free(buff);
		return (NULL);
	}
	else
	{
		free(temp);
		buff = pwd_util(buff, size);
	}
	return (buff);
}

static char	*cd_dots(char*path)
{
	char		*temp_pwd;

	temp_pwd = get_pwd();
	if (chdir(path))
	{
		if (!access(path, F_OK) || (!access(path, R_OK)
				|| !access(path, W_OK) || !access(path, X_OK)))
			printf("O_o: %s: Permission denied\n", path);
		else
			printf("O_o: %s: No such file or directory\n", path);
		g_ret_value = -1;
	}
	else if (temp_pwd == NULL)
		return (temp_pwd);
	else
	{
		free(temp_pwd);
		temp_pwd = get_pwd();
	}
	return (temp_pwd);
}

static void	cd_way(t_env *env, char *path)
{
	char	*tmp;
	char	*cd_result;
	char	*save_pwd;

	tmp = path;
	save_pwd = get_pwd();
	if ((!tmp && find_home(env) != -1) || my_strncmp(path, "~"))
		tmp = ft_strchr(env->env[find_env(env, "HOME=")], '=') + 1;
	else if (my_strncmp(tmp, "-"))
	{
		if (find_home(env) != -1)
			tmp = ft_strchr(env->env[find_env(env, "HOME=")], '=') + 1;
		if (find_oldpwd(env) != -1 && my_strncmp(save_pwd, tmp))
			tmp = ft_strchr(env->env[find_env(env, "OLDPWD=")], '=') + 1;
	}
	cd_result = cd_dots(tmp);
	if (!access(cd_result, R_OK) || !access(cd_result, X_OK))
		att_env(env, save_pwd, cd_result);
	free(cd_result);
	free(save_pwd);
}

int	cd(char *path, t_env *env)
{
	g_ret_value = 0;
	if (path && path[0] == 0)
		path = ".";
	if ((!path && find_home(env) == -1) || (find_home(env) == -1
			&& path[0] == 0) || (find_home(env) == -1 && my_strncmp(path, "~")))
	{
		printf("HOME not set\n");
		g_ret_value = -1;
	}
	else
		cd_way(env, path);
	return (g_ret_value);
}
