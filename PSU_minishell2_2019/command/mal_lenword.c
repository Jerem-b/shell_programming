/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** mal_lenword.c
*/

#include "../src/shell.h"

char ***mal_lenword(struct s_shell *shell, int nb_word, char ***dest, char *b)
{
    int len_word;
    int k = 0;

    for (int i = 0; i < shell->amnt_cmd; i++) {
        for (int j = 0; j < nb_word; j++) {
            len_word = 0;
            for(; b[k] == ' '; k++);
            for (; b[k] != ' ' && b[k] != '\0'&& b[k] != ';' && 
            b[k] != '|'&& b[k] != '<' && b[k] != '>'; k++)
                len_word++;
            dest[i][j] = malloc(sizeof(char) * (len_word + 1));
            k += 2;
        }
    }
    return dest;
}