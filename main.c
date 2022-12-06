/* fvck minishell */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	c_pid;
	char	*command;
	char	*input;
	char	**path;
	int		i;

	if (argc != 1)
		return (0);
	command = NULL;
	path = ft_split(getenv("PATH"), ':');
	i = -1;
	while (1)
	{
		input = readline("minish> ");
		c_pid = fork();
		if (c_pid == 0)
		{
			i = -1;
			while (path[++i])
			{
				command = ft_strjoin(path[i], ft_strjoin("/", input));
				if (!access(command, X_OK))
					break ;
			}
			if (path[i])
				execve(command, argv, envp);
			else
				printf("minish: command not found: %s\n", input);
			free(input);
			free(command);
			return (0);
		}
		else
			wait(NULL);
	}
	return (0);
}
