/*
** EPITECH PROJECT, 2019
** unsetenv.c
** File description:
** Unset an env var
*/

#include "mysh.h"

static int to_unset(shell_vars_t *vars, int rk, char *env_l)
{
    char *tmp = NULL;

    for (int i = 1; vars->commands[rk][i]; i++) {
        tmp = concat_words(0, vars->commands[rk][i], "=", NULL);
        if (my_strncmp(env_l, tmp, my_strlen(tmp)) == 0)
            return (arrfree_ret(0, tmp));
        free(tmp);
    }
    return (84);
}

static int unset_it(shell_vars_t *vars, int rk)
{
    char **future_envp = NULL;

    for (int i = 0; vars->envp[i]; i++) {
        if (to_unset(vars, rk, vars->envp[i]) != 0)
            future_envp = arr2concat(future_envp, 1, vars->envp[i], NULL);
    }
    arr2free(vars->envp);
    vars->envp = arr2dup(future_envp);
    arr2free(future_envp);
    return (0);
}

static int check_star(char **arr)
{
    for (int i = 1; arr[i]; i++)
        if (my_strcmp(arr[i], "*") == 0)
            return (0);
    return (84);
}

int exec_unsetenv(shell_vars_t *vars, int rk)
{
    int len = arr2len(vars->commands[rk]);

    if (vars->envp == NULL)
        return (0);
    if (len == 1)
        return (m_ret_e(84, "unsetenv", "Too few arguments"));
    if (check_star(vars->commands[rk]) == 0) {
        arr2free(vars->envp);
        vars->envp = NULL;
        arr2free(vars->path);
        vars->path = update_path(vars->envp);
        return (0);
    }
    unset_it(vars, rk);
    arr2free(vars->path);
    vars->path = update_path(vars->envp);
    return (0);
}
