/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** get_pwd.c
*/

#include "../src/shell.h"

void get_pwd(struct s_shell * shell)
{
    size_t size = 300;
    shell->current_pwd = malloc(sizeof(char) * (size + 1));
    shell->prev_pwd = malloc(sizeof(char) * (size + 1));
    getcwd(shell->current_pwd, size);
    for (int i = 0; i < shell->env_h; i++) {
        if (shell->copy_env[i][0] == 'O' && shell->copy_env[i][1] == 'L' && 
        shell->copy_env[i][2] == 'D') {
            shell->prev_pwd = get_oldpwd(shell->copy_env[i]);
        }
    }
}