/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_env.c
*/

#include "../include/minishell.h"

void my_env(char **env, struct s_shell *shell)
{
    change_path_env(shell);
    for (int i = 0; i < shell->line_env; i++) {
        for (int j = 0; j < my_strlen(env[i]); j++)
            write(1, &shell->env_cpy[i][j], 1);
        write(1, "\n", 1);
    }
}