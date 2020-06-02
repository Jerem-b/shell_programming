/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir_pipe.c
*/

#include "mysh.h"

int do_redirpipe(int *pipe_fd, int *rk, shell_vars_t *vars)
{
    pip_t pipes = {0};

    if (pipe(pipes.fd))
        return (84);
    if (dup2(pipe_fd[1], 1) == -1)
        return 84;
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    if (is_built_in(vars->commands[*rk][0]) == 0) {
        if (exec_internals(vars, rk, &pipes) == 84)
            return 84;
        else
            return 0;
    }
    if (execve(vars->commands[*rk][0], vars->commands[*rk], vars->envp) < 0)
        return 84;
    return 0;
}

int redir_pipe(int *rk, shell_vars_t *vars)
{
    pid_t pid;
    int pipe_fd[2];

    if (pipe(pipe_fd)) return 84;
    pid = fork();
    if (pid == -1) return 84;
    if (pid == 0)
        if (do_redirpipe(pipe_fd, rk, vars) == 84)
            return 84;
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    return 0;
}