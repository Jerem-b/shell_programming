/*
** EPITECH PROJECT, 2019
** ni_mode.c
** File description:
** Note interactive
*/

#include "mysh.h"

int ni_mode(shell_vars_t *vars)
{
    char *str = concat_ni_commands(vars->ac, vars->av);

    replace_char(str, '\t', ' ', 0);
    if (command_checking(str) == 84)
        return (arrfree_ret(84, str));
    command_parsing(str, vars, 1);
    launch(vars);
    return (0);
}
