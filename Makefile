##
## EPITECH PROJECT, 2023
## SBML_parser
## File description:
## Makefile
##

CC ?=	gcc

SRC = 	src/open_and_read/open_read.c \
		src/str_sep.c \
		src/free_array.c \
		src/parser.c \
		src/free_lists.c \
		src/node_add.c \
		src/print_tags.c

OBJ =	$(SRC:.c=.o)

MAIN =	src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

NAME =	SBML_parser

EXEC = ./$(NAME)

VALGRIND_PARAMS ?= '-h'

CFLAGS = -Wall -Wextra -g3
CPPFLAGS = -iquote include

MKDIR = mkdir -p

all: $(NAME)


$(NAME): 	$(OBJ) $(OBJ_MAIN)
			$(CC) $(OBJ_MAIN) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ) $(MAIN:.c=.o)

fclean: clean
		$(RM) $(NAME) vg*

re: fclean
	$(MAKE) all

valgrind: 	re
			valgrind $(EXEC) $(VALGRIND_PARAMS)

.PHONY: all lib clean fclean re valgrind