/*
** EPITECH PROJECT, 2019
** exit.c
** File description:
** Exit the terminal
*/

#include "mysh.h"

int exec_exit(shell_vars_t *vars, int rk)
{
    int len = arr2len(vars->commands[rk]);
    int val = 0;

    if (len > 2)
        return (84);
    if (len == 1) {
        free_sh_vars_ret(0, *vars);
        exit(0);
    }
    if (is_number(vars->commands[rk][1]) == 84)
        return (84);
    val = str_to_int(vars->commands[rk][1]);
    free_sh_vars_ret(0, *vars);
    exit(val);
    return (0);
}
