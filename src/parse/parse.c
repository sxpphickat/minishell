/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:48:36 by vipereir          #+#    #+#             */
/*   Updated: 2023/03/16 09:09:35 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse(char	*input, t_token	**tokens, t_env *env)
{
	char	*parsed_input;
	char	**splitted_input;

	parsed_input = pre_parse(input);
	free(input);
	if (!parsed_input || !parsed_input[0])
	{
		free(parsed_input);
		return (1);
	}
	splitted_input = parse_split(parsed_input, ' ');
	free(parsed_input);
	if (!splitted_input || !splitted_input[0])
		return (ft_free_matrix(splitted_input));
	create_tokens(splitted_input, tokens);
	ft_free_matrix(splitted_input);
	set_type(tokens);
	if (syntax_checker(tokens))
		return (clear_tokens(tokens));
	expand_env_var(tokens, env);
	remove_quotes(tokens);
	if (check_here_doc(tokens))
		return (clear_tokens(tokens));
	return (0);
}
