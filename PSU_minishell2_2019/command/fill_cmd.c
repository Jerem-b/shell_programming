/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** fill_cmd.c
*/

#include "../src/shell.h"

char ***fill_cmd(struct s_shell *shell, int nb_word, char *b, char ***dest)
{
    int k = 0;
    int pos = 0;
    int n = 0;

    for (int i = 0; i < shell->amnt_cmd; i++) {
        for (int j = 0; j < nb_word; j++) {
            n = 0;
            for(; b[k] == ' '; k++);
            for (; b[k] != ' ' && b[k] != '\0'&& b[k] !='\n'&&b[k]!=';';k++) {
                dest[i][j][n] = b[pos];
                pos++;
                n++;
            }
            k++;
            pos++;
        }
        pos++;
    }
    return dest;
}