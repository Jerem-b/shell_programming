/*
** EPITECH PROJECT, 2019
** can_be_exec.c
** File description:
** Check if command is in path and act in consequences
*/

#include "mysh.h"

static int check_special(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            return (0);
    return (84);
}

static int check_path(char **path, char **command, struct stat *sb)
{
    char *tmp = NULL;
    int i = 0;
    int len = arr2len(path);

    for (; i < len; i++) {
        tmp = concat_words(0, path[i], *command, NULL);
        if (stat(tmp, sb) != -1
            && access(tmp, X_OK) != -1
            && S_ISREG(sb->st_mode)) {
            free(*command);
            *command = my_strdup(tmp);
            return (arrfree_ret(0, tmp));
        }
        if (i != len - 1)
            free(tmp);
    }
    if (stat(tmp, sb) == -1)
        return (arrfree_ret(m_ret_e(84, *command, "Command not found"), tmp));
    if (access(tmp, X_OK) == -1 || !S_ISREG(sb->st_mode))
        error_ret(84, tmp, EACCES);
    return (arrfree_ret(84, tmp));
}

int can_be_exec(shell_vars_t *vars, int rank)
{
    struct stat s;
    int test = 0;

    test = check_special(vars->commands[rank][0]);
    if (test == 0) {
        if (stat(vars->commands[rank][0], &s) == -1)
            return (m_ret_e(84, vars->commands[rank][0], "Command not found"));
        if (!S_ISREG(s.st_mode) || access(vars->commands[rank][0], X_OK) == -1)
            return (error_ret(84, vars->commands[rank][0], EACCES));
        return (0);
    }
    if (vars->path == NULL)
        return (m_ret_e(84, vars->commands[rank][0], "Command not found"));
    if (check_path(vars->path, &vars->commands[rank][0], &s) == 84)
        return (84);
    return (0);
}
