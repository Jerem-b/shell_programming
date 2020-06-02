/*
** EPITECH PROJECT, 2019
** i_mode.c
** File description:
** Interactive
*/

#include "mysh.h"

static int reset_red(char **red)
{
    if (*red != NULL) {
        free(*red);
        *red = NULL;
    }
    return (0);
}

int i_mode(shell_vars_t *vars)
{
    char *str = NULL;
    size_t gl = 0;

    prompt(vars->envp);
    while (getline(&str, &gl, stdin) != -1) {
        replace_char(str, '\n', 0, 1);
        replace_char(str, '\t', ' ', 0);
        reset_red(&vars->shell_red);
        if (command_checking(str) == 84) {
            prompt(vars->envp);
            continue;
        }
        arr3free(vars->commands);
        command_parsing(str, vars, 0);
        launch(vars);
        prompt(vars->envp);
    }
    free(str);
    return (0);
}
