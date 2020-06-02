/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** cpy_env.c
*/

#include "../include/minishell.h"

void cpy_env(struct s_shell *shell, char **env)
{
    shell->line_env = 0;
    shell->env_cpy = 0;
    for (int i = 0; env[i] != NULL; i++)
        shell->line_env++;
    shell->env_cpy = malloc(sizeof(char *) * (shell->line_env + 1));
    for (int i = 0; i < shell->line_env; i++) {
        shell->env_cpy[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    }
    for (int i = 0; i < shell->line_env; i++) {
        for (int j = 0; j < my_strlen(env[i]); j++)
            shell->env_cpy[i][j] = env[i][j];
        shell->env_cpy[i][my_strlen(env[i])] = '\0';
    }
    shell->env_cpy[shell->line_env] = NULL;
}