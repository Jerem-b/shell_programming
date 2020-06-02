##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile
##

SRC	=	main.c\
		buildin/check_buildin.c\
		buildin/my_cd.c\
		buildin/my_env.c\
		buildin/my_exit.c\
		buildin/my_setenv.c\
		buildin/my_unsetenv.c\
		command/calc_amount.c\
		command/cpy_env.c\
		command/execute_command.c\
		command/fill_buffer.c\
		command/fill_cmd.c\
		command/make_com.c\
		command/mal_amnt_cmd.c\
		command/mal_amntword.c\
		command/mal_lenword.c\
		command/my_strtok_struct.c\
		command/transform_string.c\
		command/transform_string_cmd.c\
		command/transform_string_other.c\
		my/my_atoi.c\
		my/my_countword.c\
		my/my_free.c\
		my/my_strcmp.c\
		my/my_strlen.c\
		parser/get_oldpwd.c\
		parser/get_pwd.c\
		parser/get_paths.c\
		redirection/check_redir.c\
		redirection/my_pipe.c\
		redirection/redirection.c\
		redirection/redir_in_append.c\
		redirection/redir_in.c\
		redirection/redir_out.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CC	=	gcc

CFLAGS += -g

all:	$(NAME)
$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
	@rm -rf src/*.o
	@rm -rf *.o
	@rm -rf buildin/*.o
	@rm -rf command/*.o
	@rm -rf my/*.o
	@rm -rf parser/*.o
	@rm -rf redirection/*.o
fclean:	clean
	@rm -rf $(NAME)
re: fclean all
