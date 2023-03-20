/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:04:14 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/20 18:04:16 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_str_rem(char *str)
{
	int	len;
	int	status;

	status = 1;
	len = ft_strlen(str) - 1;
	if (str[len] == '/')
		len--;
	while (status && str[len])
	{
		if ((len == 0 && str[len] == '/'))
		{
			str[++len] = '\0';
			status = 0;
		}
		else if (str[len] == '/')
		{
			str[len] = '\0';
			status = 0;
		}
		len--;
	}
	return (str);
}

char	*ft_strjoin_cd(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
