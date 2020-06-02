/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** switch_command.c
*/

#include "../include/minishell.h"

int coding_style(struct s_shell *shell, char **env, int i)
{
    if (!my_strcmp(shell->command[0], "setenv")) {
        my_setenv(shell);
        i = 1;
    }
    if (!my_strcmp(shell->command[0], "unsetenv")) {
        my_unsetenv(shell);
        i = 1;
    }
    return i;
}

void switch_command(struct s_shell *shell, char **env)
{
    int i = 0;

    if (!my_strcmp(shell->command[0], "cd")) {
        my_cd(shell);
        i = 1;
    }
    if (!my_strcmp(shell->command[0], "exit")) {
        my_exit(shell);
        i = 1;
    }
    if (!my_strcmp(shell->command[0], "env")) {
        my_env(env, shell);
        i = 1;
    }
    i = coding_style(shell, env, i);
    if (i == 0)
        build_in_command(shell);
}