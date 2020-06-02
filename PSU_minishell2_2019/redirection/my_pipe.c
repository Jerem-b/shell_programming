/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_pipe.c
*/

#include "../src/shell.h"

void other_pipe(int *pipe_fd, char **env, char **cmd, int i)
{
    pid_t pid;
    int status;

    if ((pid = fork()) == -1)
        perror("fork");
    if (pid == 0) {
        dup2(pipe_fd[i], i);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        if (execve(cmd[0], cmd, env) == -1)
            perror("execve");
    }
    if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1)
        perror("waitpid");
}

void my_pipe(char *cmd[], char *av[], char *env[])
{
    char **cmd1 = transform_string_cmd(cmd, "|");
    char **cmd2 = transform_string_other(cmd, "|");
    int status;
    pid_t pid;
    int pipe_fd[2];

    cmd1[0] = transform_string(cmd1);
    cmd2[0] = transform_string(cmd2);
    if (pipe(pipe_fd) == -1)
        perror("pipe");
    other_pipe(pipe_fd, env, cmd1, 1);
    other_pipe(pipe_fd, env, cmd2, 0);

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1)
        perror("waitpid");
}