NAME = minishell

SRC = minishell.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

LIB = path

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all:		$(NAME)

clean:

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
