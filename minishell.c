/* fvck minishell */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*command;
	while (1)
	{
		command = readline("minish> ");
		free(command);
	}
	return (0);
}
