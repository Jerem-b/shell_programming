##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile
##

SRC	=	src/main.c\
		buildin/build_in_command.c\
		buildin/my_cd.c\
		buildin/my_env.c\
		buildin/my_exit.c\
		buildin/my_setenv.c\
		buildin/my_unsetenv.c\
		commands/change_path.c\
		commands/cpy_env.c\
		commands/fill_command.c\
		commands/get_command.c\
		commands/get_pwd.c\
		commands/switch_command.c\
		my/my_atoi.c\
		my/my_putstr.c\
		my/my_strcmp.c\
		my/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CC	=	gcc

CFLAGS += -g

all:	$(NAME)
$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	@rm -rf my/*.o
	@rm -rf commands/*.o
	@rm -rf buildin/*.o
	@rm -rf src/*.o
fclean:	clean
	@rm -rf $(NAME)
re: fclean all
