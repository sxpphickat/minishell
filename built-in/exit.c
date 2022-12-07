#include "../minishell.h"

void	ft_exit(char **input)
{
	int	i;

	i = 0;
	if (input[2])
	{
		printf("minish: too many arguments: %s\n", input[0]);
		return ;
	}
	if (!input[1])
		exit(0);

	while (input[1][i])
	{
		if (input[1][i] >= 0x30 && input[1][i] <= 0x39)
			i++;
		else
		{
			printf("minish: numeric argument required: %s\n", input[0]);
			return ;
		}
	}
	exit(ft_atoi(input[1]));
}
