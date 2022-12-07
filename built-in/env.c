#include "../minishell.h"

void	ft_env(void)
{
	extern char** environ;

	while (*environ)
	{
		printf("%s\n", *environ++);
	}
}
