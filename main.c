/* fvck minishell */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include <termios.h>

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	c_pid;
	char	*command;
	char	**input;
	char	**path;
	char	*read;
	int		i;
	struct termios		old_termios;
	struct termios		new_termios;

	tcgetattr(0, &old_termios);
	new_termios = old_termios;				// inverte os comandos ^C e ^D
	new_termios.c_cc[VEOF] = 3;
	new_termios.c_cc[VINTR] = 4;
	tcsetattr(0, TCSANOW, &new_termios);

	signal(SIGQUIT, SIG_IGN);				// ignora o ctrl backslash
	(void)argv;
	if (argc != 1)
		return (0);
	command = NULL;
	path = ft_split(getenv("PATH"), ':');
	i = -1;
	while (1)
	{
		read = readline("minish> ");
		add_history(read);
		input = ft_split(read, ' ');
		free(read);
		c_pid = fork();
		if (c_pid == 0)
		{
			if (!access(input[0], X_OK))
				execve(input[0], input, envp);
			i = -1;
			while (path[++i])
			{
				command = ft_strjoin(path[i], ft_strjoin("/", input[0]));
				if (!access(command, X_OK))
					break ;
			}
			if (path[i])
				execve(command, input, envp);
			else
				printf("minish: command not found: %s\n", input[0]);
			free(input);
			free(command);
			return (0);
		}
		else
			wait(NULL);
	}
	return (0);
}
