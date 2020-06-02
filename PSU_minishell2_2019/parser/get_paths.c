/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** get_paths.c
*/

#include "../src/shell.h"

void get_paths(struct s_shell *shell)
{
    shell->amnt_paths = 1;
    for (int i = 0; i < shell->env_h; i++) {
        if (shell->copy_env[i][0] == 'P' && shell->copy_env[i][1] == 'A' &&
        shell->copy_env[i][2] == 'T' && shell->copy_env[i][3] == 'H') {
            shell->paths = my_strtok_struct(shell->copy_env[i], ':', shell);
        }
    }
}