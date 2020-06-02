/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** check_buildin.c
*/

#include "../src/shell.h"

int other_case(char **command, struct s_shell *shell)
{
    if (my_strcmp("setenv", command[0]) == 0) {
        my_setenv();
        return 0;
    }
    else if (my_strcmp("unsetenv", command[0]) == 0) {
        my_unsetenv();
        return 0;
    }
    else
        return 1;
}

int check_buildin(char **command, struct s_shell *shell)
{
    int i = 0;

    if (my_strcmp("cd", command[0]) == 0) {
        my_cd(command, shell);
        return 0;
    }
    else if (my_strcmp("env", command[0]) == 0) {
        my_env(shell);
        return 0;
    }
    else if(my_strcmp("exit", command[0]) == 0) {
        my_exit(command);
        return 0;
    }
    if ((i = other_case(command, shell)) == 0)
        return 0;
    else
        return 1;
}