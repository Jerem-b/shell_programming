/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** redir_in.c
*/

#include "../src/shell.h"

void other_in(int *pipe_fd, char **cmd, char **env, int ret)
{
    char *com = malloc(sizeof(char) * 3000);

    if ((pipe_fd[2] = open(cmd[ret + 1], O_CREAT|O_RDWR|O_TRUNC, 0777)) <0)
            perror("open");
        else {
            close(pipe_fd[0]);
            com = transform_string(cmd);
            cmd = transform_string_cmd(cmd, ">");
            if (dup2(pipe_fd[2], 1) == -1)
                perror("dup2");
            else if(execve(com, cmd, env) == -1)
                perror("execve");
        }
}

void redir_in(char **cmd, char **env)
{
    pid_t pid;
    int pipe_fd[3];
    char buffer[1024];
    int ret;

    for (ret = 0; my_strcmp(cmd[ret], ">") != 0; ret++);
    if(pipe(pipe_fd) == -1)
        perror("pipe");
    if ((pid = fork()) == -1)
        perror("fork");
    else if (pid == 0)
        other_in(pipe_fd, cmd, env, ret);
    else {
        close(pipe_fd[1]);
        while((ret = read(pipe_fd[0], buffer, 1023)) != 0) {
            buffer[ret] = 0;
            write(pipe_fd[2], buffer, my_strlen(buffer));
        }
    }
}