/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:13:51 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/03 12:00:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "src/utils/libft/libft.h"
# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>

/* 
# define PIPE
# define OUTPUT 2
# define INPUT 3
# define HERE_DOC 4
# define APPEND 5
 */

enum	operators {
	PIPE = 1,
	OUTPUT = 2,
	INPUT = 3,
	HERE_DOC = 4,
	APPEND = 5,
	AND = 6,
	OR = 7
};

# define COMMAND 8
# define PARAM 9

# define S_QUOTE 11
# define D_QUOTE 22

extern int	g_ret_value;

// tokens struct
typedef struct s_env
{
	char	**env;
}	t_env;

typedef struct s_token{
	char				*word;
	int					type;
	int					is_redirect;
	int					here_doc_fd;
	struct s_token		*prev;
	struct s_token		*next;
}	t_token;

typedef struct s_redirect_list
{
	int						type;
	char					**args;
	int						here_doc_fd;
	struct s_cmd_list		*father_cmd;
	struct s_redirect_list	*prev;
	struct s_redirect_list	*next;

}	t_redirect_list;

typedef struct s_cmd_list
{
	char				**argv;

	int					in;
	int					out;
	pid_t				pid;
	int					does_have_redirect;
	t_redirect_list		*redirect;
	struct s_cmd_list	*prev;
	struct s_cmd_list	*next;
}	t_cmd_list;

// builtin functions

int				check_built_in(char *input[]);
void			exec_builtin(t_cmd_list **cmd_head, t_env *env,
					t_cmd_list **master_head);
int				ft_choose_builtin(char *input[], t_env *env,
					t_cmd_list **master_head);
int				ft_pwd(void);
void			ft_exit(char **input, t_cmd_list **master_head, t_env *env);
int				ft_env(t_env *env, char **input);
int				ft_echo(char	**input);
int				ft_export(t_env *env, char **input);
int				ft_env_unset(t_env *env, char **input);
int				cd(char *path, t_env *env);
int				my_strncmp(const char *s1, const char *s2);
char			*pwd_util(char *buff, int size);
void			init_oldpwd(t_env *env);

// stdin functions

char			*get_input(t_env *env);
char			*pre_parse(char *str);

// parser functions

int				parse(char	*input, t_token	**tokens, t_env *env);
void			quotes_switch(char c, int *status);
void			dquotes_switch(char c, int *status);
char			**parse_split(char const *s, char c);
void			add_token(t_token **head, char *word);
void			create_tokens(char **splited, t_token **tokens);
int				is_operator(char *op);
void			set_type(t_token **tokens);
void			expand_env_var(t_token **tokens, t_env *env);
int				ft_here_doc(char *delimiter, t_token *token);
int				check_here_doc(t_token **tokens);
int				syntax_checker(t_token **tokens);
void			*syntax_error_free(char *to_free);
void			remove_quotes(t_token **tokens);
char			*expand_env_case(char *word, char *new_word,
					int *i, t_env *env);
char			*expand_ret_val_case(char *new_word, int *i);
char			have_quotes(char	*word);
char			have_dquotes(char	*word);
char			*single_quotes_jump(char *word, char *new_word, int *i);
char			*ft_charjoin(char const *s1, char const	c);

// new exec funcs

t_cmd_list		*add_cmd_node(t_cmd_list **cmds_head);
t_redirect_list	*add_redirect_node(t_redirect_list **redirect_head);
void			exec_commands(t_cmd_list **cmds_head, t_env *env);
int				redirection_setup(t_redirect_list **redirect, t_cmd_list **cmd);
void			exec_cmd(t_cmd_list **cmd_head, t_env *env);

// new exec utils

void			clear_cmds(t_cmd_list	**cmd_head);
void			pop_cmd(t_cmd_list **cmd_head);
void			pop_redirect(t_redirect_list **redirect_head);
void			print_cmd_list(t_cmd_list	*cmds);

// exec functions

int				execer(t_token **cmds, t_env *env);

int				argv_size(t_token	**tokens);
t_cmd_list		*build_commands(t_token	**tokens);
void			wait_pids(t_cmd_list *cmds);

// exec utils functions

void			set_exit_status(int exit_status);
int				command_not_found(t_cmd_list	*cmd);
int				is_a_dir(t_cmd_list	*cmd);
void			print_matrix(char	**str);
int				check_dir(char	*path);
void			check_empty_quotes(char *new_read);

// utils functions

int				return_free(void *to_free, int to_return);
char			*ft_str_rem(char *str);
int				find_env(t_env *env, char *env_search);
int				array_counter(char **arr);
void			print_cmds(t_token **list);
int				clear_tokens(t_token **tokens);
int				ft_free_matrix(char **matrix);
char			*find_path(char	*cmd, t_env *env);
char			**matrix_dup(char **mat);
char			*search_delimiter(char *s1);
int				find_errors_export(char *new_env);
int				check_export(char *new_env);
int				find_env_exp(t_env *env, char *env_search);
int				find_ret_env(t_env *env, char *env_search);
int				find_pwd(t_env *env);
int				find_old(t_env *env);
int				find_ret_env(t_env *env, char *env_search);
int				find_pwd(t_env *env);
int				find_old(t_env *env);
int				find_home(t_env *env);
int				find_oldpwd(t_env *env);
void			exec_fork(t_env *env, t_cmd_list **master_head,
					t_cmd_list	*cmd, int *fd);
void			exec_else(t_cmd_list	*cmd, int *fd, int pid);
int				find_errors_unset(char *new_env);
int				check_unset(char *new_env);

// signal functions

int				jump_line(void);
void			log_out_interface(char *read, t_env *env);
void			handler_sigint(int sig);

// cmd list functions

#endif
