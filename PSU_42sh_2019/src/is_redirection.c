/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** is_redirection.c
*/

#include "mysh.h"

int redirect(char sep, shell_vars_t *vars, int *rk, pip_t pipes)
{
    if (sep == '>')
        return redir_out(rk, vars);
    if (sep == 'a')
        return redir_out_append(rk, vars);
    if (sep == 'b')
        return 130;
    if (sep == '<')
        return redir_in(rk, vars);
    if (sep == '|')
        return redir_pipe(rk, vars);
    return 0;
}

int i_rd(char sep)
{
    if (sep == '>' || sep == '<' || sep == '|' || sep == 'a' || sep == 'b')
        return 0;
    else
        return 84;
}