/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_setenv.c
*/

#include "../include/minishell.h"

void change_environement_var(struct s_shell *shell, int i)
{
    int j = 0;
    int k = 0;

    for (; shell->env_cpy[i][j] != '='; j++);
    j++;
    for (;shell->command[2][k] != '\0'; k++)
        shell->env_cpy[i][j + k] = shell->command[2][k];
    for (; shell->env_cpy[i][j + k] != '\0'; k++)
        shell->env_cpy[i][j + k] = 0;
}

void create_new_variable(struct s_shell *shell)
{
    shell->line_env++;
    shell->env_cpy = malloc(sizeof(char *) * (shell->line_env + 1));
    shell->env_cpy[shell->line_env] = malloc(sizeof(char) *
    (my_strlen(shell->command[1])));
    for (int i = 0; i < my_strlen(shell->command[1]); i++)
        shell->env_cpy[shell->line_env][i] = shell->command[1][i];
    shell->env_cpy[shell->line_env][my_strlen(shell->command[1])] = '\0';
}

void my_setenv(struct s_shell *shell)
{
    int i = 0;
    int status = 0;

    for (int i = 0; i < shell->line_env; i++) {
        if (shell->env_cpy[i][0] ==shell->command[1][0] && shell->env_cpy[i][1]
         == shell->command[1][1] && shell->env_cpy[i][2]
         == shell->command[1][2]) {
                change_environement_var(shell, i);
                status = 1;
        }
    }
    if (status == 0)
        create_new_variable(shell);
}