/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_cd.c
*/

#include "../include/minishell.h"

int other_case(struct s_shell *shell)
{
    if (shell->amnt_param >= 2) {
        my_putstr("cd: too many arguments\n");
        exit(84);
    }
    if (shell->amnt_param == 0 || shell->command[1][0] == '~') {
        chdir("/home");
        return 1;
    }
    else
        return 0;
}

void my_cd(struct s_shell *shell)
{
    if (other_case(shell) == 0)
    if (shell->command[1][0] == '-') {
        chdir(shell->prev_dir);
        shell->prev_dir = malloc(my_strlen(shell->current_dir) + 1);
        for (int i = 0; i < my_strlen(shell->current_dir); i++)
            shell->prev_dir[i] = shell->current_dir[i];
        shell->prev_dir[my_strlen(shell->current_dir)] = '\0';
    }
    else if (chdir(shell->command[1]) == 0) {
        shell->prev_dir = malloc(my_strlen(shell->current_dir) + 1);
        for (int i = 0; i < my_strlen(shell->current_dir); i++)
            shell->prev_dir[i] = shell->current_dir[i];
        shell->prev_dir[my_strlen(shell->current_dir)] = '\0';
    }
    else
        perror("cd");
}