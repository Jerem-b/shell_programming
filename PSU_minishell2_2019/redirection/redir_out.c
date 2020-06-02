/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** redir_out.c
*/

#include "../src/shell.h"

void redir_out(char **cmd, char **env)
{
    int fd, status, filename_pos;
    pid_t pid;

    for (filename_pos = 0; my_strcmp(cmd[filename_pos], "<"); filename_pos++);
    filename_pos++;
    if ((fd = open(cmd[filename_pos], O_RDONLY)) == -1)
        perror("open");
    if ((pid = fork()) == -1)
        perror("fork");
    if (pid == 0) {
        cmd[0] = transform_string(cmd);
        cmd = transform_string_cmd(cmd, "<");
        dup2(fd, 0);
        close(fd);
        if (execve(cmd[0], cmd, env) == -1)
            perror("execve");
    }
    if (waitpid(pid, &status, WUNTRACED | WCONTINUED) == -1)
        perror("waitpid");
    close(fd);
}