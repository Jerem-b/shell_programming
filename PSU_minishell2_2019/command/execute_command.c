/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** execute_command.c
*/

#include "../src/shell.h"

void execute_command(char **command, char **av, char **env)
{
    char *cmd;
    pid_t pid = fork();
    int status;

    cmd = transform_string(command);
    if (pid == 0) {
        if (execve(cmd, command, env) != 0) {
            write(1, command[0], my_strlen(command[0]));
            write(1, ": Command not found.\n", 22);
        }
    }
    else
        waitpid(pid, &status, WCONTINUED);
    kill(pid, 0);
}