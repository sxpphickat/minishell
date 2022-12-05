/* fvck minishell */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	c_pid;
	char	*command;
	char	buff[100];
	char	*fenv[] = {NULL};

	if (argc != 1)
		return (0);
	printf("%s\n", getcwd(buff, 99));
	while (1)
	{
		command = readline("minish> ");
		c_pid = fork();
		if (c_pid == 0)
		{
			execve(command, argv, fenv);
			free(command);
			return (0);
		}
		else
			wait(NULL);
		free(command);
	}
	return (0);
}
