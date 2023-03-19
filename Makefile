NAME = minishell

SRC =	main.c \
		src/built-in/cd.c \
		src/built-in/choose_builtin.c \
		src/built-in/pwd.c \
		src/built-in/env.c \
		src/built-in/exit.c \
		src/built-in/echo.c \
		src/built-in/unset.c \
		src/built-in/export.c \
		src/stdin/get_input.c \
		src/exec/exec.c \
		src/exec/add_nodes.c \
		src/exec/print_cmd_list.c \
		src/exec/exec_commands.c \
		src/exec/redirection_setup.c \
		src/exec/exec_cmd.c \
		src/exec/exec_utils.c \
		src/exec/command_not_found.c \
		src/exec/is_a_dir.c \
		src/exec/wait_pids.c \
		src/exec/set_exit_status.c \
		src/exec/clear_cmds.c \
		src/exec/build_commands.c \
		src/utils/cd_utils.c \
		src/utils/matrix_dup.c \
		src/utils/print_cmds.c \
		src/utils/clear_tokens.c \
		src/utils/free_matrix.c \
		src/utils/finds.c \
		src/utils/export_utils.c \
		src/utils/cd_utils_finds.c \
		src/utils/choose_builtins_utils.c \
		src/parse/new_cmd_node.c \
		src/parse/parse.c \
		src/parse/set_type.c \
		src/parse/parse_split.c \
		src/parse/expand_env_var.c \
		src/parse/expand_utils.c \
		src/parse/pre_parse.c \
		src/parse/pre_parse_utils.c \
		src/parse/create_nodes.c \
		src/parse/here_doc.c \
		src/parse/remove_quotes.c \
		src/parse/syntax_checker.c \
		src/signals/signal_ctrl_c.c \
		src/signals/ctrl_d.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

CPPFLAGS = -I /opt/homebrew/Cellar/readline/8.2.1/include

LDFLAGS = -L /opt/homebrew/Cellar/readline/8.2.1/lib

CPPFLAGS += -I ~/.brew/opt/readline/include

LDFLAGS += -L ~/.brew/opt/readline/lib

RM = rm -f

LIB = src/utils/libft/libft.a

$(NAME):	$(SRC) $(LIB)
			$(CC) $(CFLAGS) $(SRC) $(LIB) -lreadline $(CPPFLAGS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

$(LIB):
			make -C src/utils/libft

clean:
			make clean -C src/utils/libft

fclean:		clean
			$(RM) $(NAME)
			make fclean -C src/utils/libft

re:			fclean all

run:		all
			./minishell

val:		all
			valgrind --leak-check=full ./minishell

.PHONY: all clean fclean re
