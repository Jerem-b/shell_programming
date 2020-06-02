/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_env.c
*/

#include "../src/shell.h"

void my_env(struct s_shell *shell)
{
    for (int i = 0; i < shell->env_h; i++) {
        write(1, shell->copy_env[i], my_strlen(shell->copy_env[i]) + 2);
        write(1, "\n", 1);
    }
}