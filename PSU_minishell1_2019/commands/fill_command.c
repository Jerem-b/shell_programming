/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** fill_command.c
*/

#include "../include/minishell.h"

void fill_command(struct s_shell *shell, int nbr_word, char *str, int len_word)
{
    int k = 0;

    for (int i = 0; i < nbr_word; i++) {
        for (; str[len_word] == ' '; len_word++){
        }
        for (k = 0; str[len_word] != ' ' && str[len_word + 1] != '\0'; k++) {
            shell->command[i][k] = str[len_word];
            len_word++;
        }
        shell->command[i][len_word] = '\0';
        len_word++;
    }
    shell->command[nbr_word] = NULL;
}