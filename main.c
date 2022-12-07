/* fvck minishell */

#include "minishell.h"

void	ft_pwd(void)
{
	char	*buff;

	buff = malloc(100);
	getcwd(buff, 100);
	printf("%s\n", buff);
}

void	ft_exit(void)
{
	exit(0);
}

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
	tcsetattr(0, TCSANOW, &new_termios);	// isso está invertendo até fora do minishell, vou tentar criar uma saida limpa que desnverta isso

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
		if (!ft_strncmp(input[0], "pwd", ft_strlen(input[0]))) // usar um array com todos os nomes de built-ins
			ft_exit();
		else
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
