/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strtok_struct.c
*/

#include "../src/shell.h"

char **my_strtok_struct(char *str, const char delim, struct s_shell *shell)
{
    char **dest;
    int offset;
    int count = 0;
    int pos = 0;
    int k = 0;

    shell->amnt_paths = calc_amount(str, delim);
    dest = malloc(sizeof(char *) * (shell->amnt_paths + 1));
    for (offset = 0; str[offset] != '='; offset++);
    offset++;
    for (int i = offset; str[i] != '\0'; i++) {
        count++;
        if (str[i] == delim) {
            dest[pos] = malloc(sizeof(char) * (count + 1));
            pos++, i++;
            count = 0;
        }
    }
    dest[pos] = malloc(sizeof(char) * (300));
    dest = fill_buffer(shell->amnt_paths, str, dest, delim);
}