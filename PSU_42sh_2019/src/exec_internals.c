/*
** EPITECH PROJECT, 2019
** exec_internals.c
** File description:
** Exec internal commands
*/

#include "mysh.h"

static int find_built_in(char *str)
{
    char *arr[] = {"env", "exit", "cd", "setenv", "unsetenv", "echo", NULL};
    int i = 0;

    while (arr[i])
        if (my_strcmp(arr[i++], str) == 0)
            return (--i);
    return (-1);
}

int exec_internals(shell_vars_t *vars, int *rk, pip_t UNUSED *pipes)
{
    int code = 0;
    int internal_type = find_built_in(vars->commands[*rk][0]);

    switch (internal_type) {
        case (0): code = exec_env(vars, *rk);
            break;
        case (1): code = exec_exit(vars, *rk);
            break;
        case (2): code = exec_cd(vars, *rk);
            break;
        case (3): code = exec_setenv(vars, *rk);
            break;
        case (4): code = exec_unsetenv(vars, *rk);
            break;
        case (5): code = exec_echo(vars, *rk);
            break;
        default: code = 84;
    }
    return (code);
}
