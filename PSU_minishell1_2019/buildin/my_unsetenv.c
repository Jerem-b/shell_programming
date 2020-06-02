/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_unsetenv.c
*/

#include "../include/minishell.h"

void remove_environement_var(struct s_shell *shell, int i)
{
    for (int j = 0; shell->env_cpy[i][j] != '\0'; j++)
        shell->env_cpy[i][j] = 0;
}

void my_unsetenv(struct s_shell *shell)
{
    int i = 0;

    for (int k = 1; k <= shell->amnt_param; k++) {
        for (int i = 0; i < shell->line_env; i++) {
            if (shell->env_cpy[i][0] ==shell->command[k][0] &&
            shell->env_cpy[i][1] == shell->command[k][1] &&
            shell->env_cpy[i][2] == shell->command[k][2]) {
                remove_environement_var(shell, i);
            }
        }
    }
}