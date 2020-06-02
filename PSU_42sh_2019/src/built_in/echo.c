/*
** EPITECH PROJECT, 2019
** echo.c
** File description:
** Echo command
*/

#include "mysh.h"

int exec_echo(shell_vars_t *vars, int rk)
{
    int len = arr2len(vars->commands[rk]);
    int test_n = (len > 1) ? my_strcmp(vars->commands[rk][1], "-n") : 1;
    int i = (test_n == 0) ? 2 : 1;

    for (; i < len; i++) {
        my_write(1, vars->commands[rk][i]);
        if (i != len - 1)
            my_write(1, " ");
    }
    if (test_n != 0)
        my_write(1, "\n");
    return (0);
}
