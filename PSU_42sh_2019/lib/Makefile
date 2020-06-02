##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for libfirebolt
##

NAME = libfirebolt.a

SRC = $(wildcard *.c)

CC ?= cc

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	echo "Building libfirebolt..."

clean:
	$(RM) $(OBJ)
	echo "Cleaning libfirebolt..."

fclean: clean
	$(RM) $(NAME)
	echo "Deleting libfirebolt..."

re: fclean all
