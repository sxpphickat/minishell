/* fvck minishell */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	printf("%s\n", readline("minish> "));
	return (0);
}
