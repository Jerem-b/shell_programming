/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_exit.c
*/

#include "../include/minishell.h"

int my_exit(struct s_shell *shell)
{
    my_putstr("exit\n");
    if (shell->amnt_param == 0)
        exit(0);
    else
        exit(my_atoi(shell->command[1]));
}