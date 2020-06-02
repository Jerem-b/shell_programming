/*
** EPITECH PROJECT, 2019
** setenv.c
** File description:
** Set or reset an env var
*/

#include "mysh.h"

static int set_the_env(shell_vars_t *vars, int rk, int len)
{
    int i = find_in_env(vars->envp, vars->commands[rk][1]);
    char *str = NULL;

    if (len == 2)
        str = concat_words(0, vars->commands[rk][1], "=", NULL);
    if (len == 3)
        str = concat_words(0, vars->commands[rk][1], "=",
        vars->commands[rk][2], NULL);
    if (i == -1)
        vars->envp = arr2concat(vars->envp, 1, str, NULL);
    else {
        free(vars->envp[i]);
        vars->envp[i] = NULL;
        vars->envp[i] = concat_words(1, vars->envp[i], str, NULL);
    }
    free(str);
    return (0);
}

int exec_setenv(shell_vars_t *vars, int rk)
{
    int len = arr2len(vars->commands[rk]);

    if (len == 1)
        return (exec_env(vars, rk));
    if (len > 3)
        return (m_ret_e(84, "setenv", "Too many arguments"));
    if (check_alpha(vars->commands[rk][1]) == 84)
        return (m_ret_e(84, "setenv",
            "Variable name must contain alphanumeric characters"));
    set_the_env(vars, rk, len);
    arr2free(vars->path);
    vars->path = update_path(vars->envp);
    return (0);
}
