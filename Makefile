CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = fillit

SRCS += ./src/main.c
SRCS += ./src/ft_strdup.c
SRCS += ./src/ft_putendl.c
SRCS += ./src/ft_putstr.c
SRCS += ./src/ft_putchar.c
SRCS += ./src/ft_strlen.c
SRCS += ./src/ft_strnew.c
SRCS += ./src/ft_lstadd.c
SRCS += ./src/ft_lstdel.c
SRCS += ./src/ft_lstdelone.c
SRCS += ./src/ft_lstnew.c
SRCS += ./src/ft_memalloc.c
SRCS += ./src/ft_memcpy.c
SRCS += ./src/ft_memdel.c
SRCS += ./src/ft_memset.c
SRCS += ./src/ft_parsing.c
SRCS += ./src/ft_parsing_functions.c
SRCS += ./src/ft_convert.c
SRCS += ./src/ft_convert_functions.c
SRCS += ./src/ft_solve.c
SRCS += ./src/ft_utils.c

INC = ./inc/fillit.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $@	

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean
