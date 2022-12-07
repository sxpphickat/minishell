NAME = minishell

SRC =	main.c \
		built-in/pwd.c \
		built-in/exit.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

LIB = libft/libft.a

$(NAME):	$(SRC) $(LIB)
			$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

all:		$(NAME)

$(LIB):
			make -C libft

clean:
			make clean -C libft

fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY: all clean fclean re
