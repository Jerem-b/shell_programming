/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** change_path.c
*/

#include "../include/minishell.h"

void fill_current_path(struct s_shell *shell, int i)
{
    int j = 0;
    int k = 0;

    for (; shell->env_cpy[i][j] != '='; j++);
    j++;
    for (; shell->current_dir[k] != '\0'; k++)
        shell->env_cpy[i][j + k] = shell->current_dir[k];
    for(; shell->env_cpy[i][j + k] != '\0'; k++)
        shell->env_cpy[i][j + k] = 0;
}

void fill_old_path(struct s_shell *shell, int i)
{
    int j = 0;
    int k = 0;

    for (; shell->env_cpy[i][j] != '='; j++)
    j++;
    for (; shell->prev_dir[k] != '\0'; k++)
        shell->env_cpy[i][j + k] = shell->prev_dir[k];
    for(; shell->env_cpy[i][j + k] != '\0'; k++)
        shell->env_cpy[i][j + k] = 0;
}

void change_path_env(struct s_shell *shell)
{
    for (int i = 0; i < shell->line_env; i++) {
        if (shell->env_cpy[i][0] == 'P' && shell->env_cpy[i][1] == 'W')
            fill_current_path(shell, i);
        if (shell->env_cpy[i][0] == 'O' && shell->env_cpy[i][1] == 'L')
            fill_old_path(shell, i);
    }
}