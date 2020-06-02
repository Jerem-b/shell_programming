/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_free.c
*/

#include "../src/shell.h"

void my_free(struct s_shell *shell)
{
    for (int i = 0; i < shell->env_h; i++)
        free(shell->copy_env[i]);
    free(&shell->copy_env);
}