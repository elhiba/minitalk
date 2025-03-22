NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = ft_printf.c ft_printf_utils.c ft_printf_advanced.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
