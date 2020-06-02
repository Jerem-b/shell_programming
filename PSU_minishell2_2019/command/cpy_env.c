/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** cpy_env.c
*/

#include "../src/shell.h"

void cpy_env(struct s_shell *shell, char **env)
{
    shell->env_h = 0;
    for (int i = 0; env[i] != NULL; i++) {
        shell->env_h++;
    }
    shell->copy_env = malloc(sizeof(char *) * (shell->env_h + 1));
    for (int i = 0; i < shell->env_h; i++) {
        shell->copy_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    }
    for (int i = 0; i < shell->env_h; i++) {
        for (int j = 0; j <= my_strlen(env[i]); j++)
            shell->copy_env[i][j] = env[i][j];
        shell->copy_env[i][my_strlen(env[i])] = '\0';
    }
}