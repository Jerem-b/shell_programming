/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** get_command.c
*/

#include "../include/minishell.h"

void get_command(struct s_shell *shell, char *str)
{
    int nbr_word = 1;
    int len_word = 0;

    shell->command = 0;
    shell->amnt_param = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' && str[i - 1] != ' ') || str[i] == '\0') {
            nbr_word++;
            shell->amnt_param++;
        }
    }
    shell->command = malloc(sizeof(char *) * (nbr_word + 2));
    for (int i = 0; i <= nbr_word; i++) {
        len_word = 0;
        for (int j = 0; str[j] != ' ' && str[j] != '\0'; j++) {
            len_word++;
        }
        shell->command[i] = malloc(len_word + 1);
    }
    fill_command(shell, nbr_word, str, 0);
}