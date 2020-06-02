##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for mysh
##

NAME = 42sh

SRC = main.c $(wildcard src/*.c src/built_in/*.c)

CFLAGS += -I./include -I./lib

export CFLAGS += -Wall -Wextra -g

LDFLAGS += -lfirebolt -L./lib

export CC = cc

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	make -C lib
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	echo "Building the project..."

clean:
	make -C ./lib clean
	rm -f $(OBJ)
	echo "Cleaning the project..."

fclean: clean
	make -C ./lib fclean
	rm -f $(NAME)
	echo "Deleting the binary..."

re: fclean all
