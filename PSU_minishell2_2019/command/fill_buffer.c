/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** fill_buffer.c
*/

#include "../src/shell.h"

char **fill_buffer(int amnt, char *str, char **dest, char delim)
{
    int count;
    int k = 0;
    int offset = 0;

    for (; str[offset] != '='; offset++);
    offset++;
    for (int i = 0; i < amnt; i++) {
        for (count = 0; str[k+offset]!=delim && str[k+offset]!='\0'; count++) {
            dest[i][count] = str[k + offset];
            k++;
        }
        k++;
    }
    return dest;
}