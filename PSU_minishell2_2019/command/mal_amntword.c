/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** mal_amntword.c
*/

#include "../src/shell.h"

char ***mal_amntword(struct s_shell *shell, char *buffer, int pos, char ***dest, int nb_word)
{
    for (int i = 0; i < shell->amnt_cmd; i++) {
        for (; buffer[pos] != '\0'&& buffer[pos] != ';' && buffer[pos] != '|'&&
         buffer[pos] != '<' && buffer[pos] != '>'; pos++) {
            if ((buffer[pos]==' '&&buffer[pos - 1]!=' ')||buffer[pos] == '\0'){
                nb_word++;
            }
        }
        dest[i] = malloc(sizeof(char *) * (nb_word + 2));
    }
    return dest;
}