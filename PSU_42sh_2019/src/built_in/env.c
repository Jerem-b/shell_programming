/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** Display env
*/

#include "mysh.h"

int exec_env(shell_vars_t UNUSED *vars, int UNUSED rk)
{
    if (vars->envp != NULL)
        arr2disp(vars->envp, 0);
    return (0);
}
