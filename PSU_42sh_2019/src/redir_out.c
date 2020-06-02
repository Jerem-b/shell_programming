/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redir_out.c
*/

#include "mysh.h"

int do_redirout(int *pipe_fd, char *filename, int *rk, shell_vars_t *vars)
{
    pip_t pipes = {0};

    if (pipe(pipes.fd) == -1)
        return (84);
    if ((pipe_fd[2] = open(filename, O_CREAT|O_RDWR|O_TRUNC, 0664)) < 0)
        return 84;
    else {
        close(pipe_fd[0]);
        if (dup2(pipe_fd[2],1)== -1)
            return 84;
        if (is_built_in(vars->commands[*rk][0]) == 0)
            return exec_internals(vars, rk, &pipes);
        if (execve(vars->commands[*rk][0], vars->commands[*rk], vars->envp)<0)
            return 84;
    }
    return 0;
}

int redir_out(int *rk, shell_vars_t *vars)
{
    pid_t pid;
    int pipe_fd[3];
    int ret = 0;
    char buffer[1024];
    char *filename = vars->commands[*rk+1][0];

    if (pipe(pipe_fd) == -1 || (pid = fork()) == -1)
        return 84;
    else if (pid == 0) {
        if (do_redirout(pipe_fd, filename, rk, vars) == 84)
            return 84;
    }
    else {
        close(pipe_fd[1]);
        while ((ret = read(pipe_fd[0], buffer, 1023)) != 0)
            write(pipe_fd[2], buffer, my_strlen(buffer));
    }
    return -1;
}