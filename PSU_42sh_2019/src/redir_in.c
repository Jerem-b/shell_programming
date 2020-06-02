/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir_in.c
*/

#include "mysh.h"

int redir_in(int *rk, shell_vars_t *vars)
{
    int fd, status;
    pid_t pid;
    char *filename = vars->commands[*rk+1][0];

    if ((fd = open(filename, O_RDONLY)) == -1)
        return 84;
    if ((pid = fork()) == -1)
        return 84;
    if (pid == 0) {
        dup2(fd, 0);
        close(fd);
        if (execve(vars->commands[*rk][0], vars->commands[*rk], vars->envp) == -1)
            return 84;
    }
    if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1)
        return 84;
    close(fd);
    return -1;
}