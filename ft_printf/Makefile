NAME = libftprintf.a

SRCS = ft_printf.c ft_functions.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
