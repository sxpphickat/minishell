#include "../minishell.h"

void	ft_pwd(void)
{
	char	*buff;
	int		size;

	size = 1;
	buff = malloc(sizeof(char) * size);
	while (!getcwd(buff, size))
	{
		free(buff);
		size++;
		buff = malloc(sizeof(char) * size);
	}
	printf("%s\n", buff);
	free(buff);
}
