/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** make_com.c
*/

#include "../src/shell.h"

char ***make_com(char *buffer, struct s_shell *shell)
{
    char ***dest;
    int pos = 0;
    int nb_word = 1;

    dest = mal_amnt_cmd(dest, shell, buffer);
    for (int i = 0; i < shell->amnt_cmd; i++) {
        for (; buffer[pos] != '\0'&& buffer[pos] != ';'; pos++) {
            if ((buffer[pos]==' '&&buffer[pos - 1]!=' ')||buffer[pos] == '\0')
                nb_word++;
        }
        dest[i] = malloc(sizeof(char *) * (nb_word + 2));
    }
    dest = mal_lenword(shell, nb_word, dest, buffer);
    dest = fill_cmd(shell, nb_word, buffer, dest);
    return dest;
}