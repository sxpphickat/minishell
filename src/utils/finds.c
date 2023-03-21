/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:59:52 by dcoutinh          #+#    #+#             */
/*   Updated: 2023/03/16 10:30:51 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_env(t_env *env, char *env_search)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(env_search);
	while (env->env[i])
	{
		if (!ft_strncmp(env->env[i], env_search, len))
			return (i);
		i++;
	}
	return (i);
}

static char	*search_in_path(char **path, char *slash_cmd, char *cmd)
{
	char	*cmd_path;
	int		i;

	cmd_path = NULL;
	i = -1;
	while (path[++i])
	{
		cmd_path = ft_strjoin(path[i], slash_cmd);
		if (!access(cmd_path, X_OK))
			break ;
		else
			free(cmd_path);
	}
	if (!path[i])
		return (ft_strdup(cmd));
	return (cmd_path);
}

char	*find_path(char	*cmd, t_env *env)
{
	char	*cmd_path;
	char	*str_path;
	char	**path;
	char	*slash_cmd;

	if (!access(cmd, X_OK))
		return (cmd);
	cmd_path = NULL;
	str_path = env->env[find_env(env, "PATH")];
	if (!str_path)
		return (cmd);
	path = ft_split(ft_strchr(str_path, '=') + 1, ':');
	slash_cmd = ft_strjoin("/", cmd);
	cmd_path = search_in_path(path, slash_cmd, cmd);
	free(slash_cmd);
	ft_free_matrix(path);
	free(cmd);
	return (cmd_path);
}
