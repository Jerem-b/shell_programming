/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** build_in_command.c
*/

#include "../include/minishell.h"

char *transfrom_string(struct s_shell *shell)
{
    char *buff = malloc(300);

    if (shell->command[0][0] == '/' && shell->command[0][1] == 'b' &&
    shell->command[0][2] == 'i' && shell->command[0][3] == 'n')
        return shell->command[0];
    else {
        buff[0] = '/';
        buff[1] = 'b';
        buff[2] = 'i';
        buff[3] = 'n';
        buff[4] = '/';
        for (int i = 0; i < my_strlen(shell->command[0]); i++)
            buff[i + 5] = shell->command[0][i];
        buff[my_strlen(shell->command[0]) + 5] = '\0';
        return buff;
    }
}

void build_in_command(struct s_shell *shell)
{
    char *command = malloc(300);
    pid_t pid = fork();
    int status;

    command = transfrom_string(shell);
    if (pid == 0) {
        if (execve(command, shell->command, shell->env_cpy) != 0) {
            my_putstr(shell->command[0]);
            my_putstr(": Command not found.\n");
        }
        if (signal(SIGSEGV, SIG_IGN))
            my_putstr("Segmentation fault\n");
    }
    else
        waitpid(pid, &status, WCONTINUED);
    kill(pid, 0);
}