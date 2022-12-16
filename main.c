/* fvck minishell */

#include "minishell.h"

int	check_built_in(char *input[])
{
	if (!ft_strncmp(input[0], "pwd", ft_strlen("pwd")))
		ft_pwd();
	else if (!ft_strncmp(input[0], "exit", ft_strlen("exit")))
		ft_exit(input);
	else if (!ft_strncmp(input[0], "echo", ft_strlen("echo")))
		printf("not done yet\n");
	else if (!ft_strncmp(input[0], "cd", ft_strlen("cd")))
		printf("not done yet\n");
	else if (!ft_strncmp(input[0], "export", ft_strlen("export")))
		printf("not done yet\n");
	else if (!ft_strncmp(input[0], "unset", ft_strlen("unset")))
		printf("not done yet\n");
	else if (!ft_strncmp(input[0], "env", ft_strlen("env")))
		ft_env();
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	c_pid;
	char	*command;
	char	**input;
	char	**path;
	char	*read;
	int		i;
/*
	struct termios		old_termios;
	struct termios		new_termios;


	tcgetattr(0, &old_termios);
	new_termios = old_termios;				// inverte os comandos ^C e ^D
	new_termios.c_cc[VEOF] = 3;
	new_termios.c_cc[VINTR] = 4;
	tcsetattr(0, TCSANOW, &new_termios);	// isso está invertendo até fora do minishell, vou tentar criar uma saida limpa que desnverta isso
											//
*/

	signal(SIGQUIT, SIG_IGN);				// ignora o ctrl backslash
	(void)argv;
	if (argc != 1)
		return (0);
	command = NULL;
	path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (1)
	{
		read = readline("minish> ");
		add_history(read);
		input = ft_split(read, ' ');
		free(read);

		if (input[0][0] == '$')
		{
			char *var = ft_strjoin(&input[0][1], "=");
			i = 0;
			while (envp[i])
			{
				if (!ft_strncmp(envp[i], var, ft_strlen(var))) // pega as variaveis de sistema
					printf("%s\n", envp[i]);
				i++;
			}
		}
		else if (check_built_in(input))
			continue ;
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
			waitpid(c_pid, 0, 0);
	}
	return (0);
}
