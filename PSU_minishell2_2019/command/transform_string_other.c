/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** transform_string_other.c
*/

#include "../src/shell.h"

char **transform_string_other(char **str, char *separator)
{
    char **buf;
    int pos = 0;
    int i = 0;

    for(; my_strcmp(str[pos], separator) != 0; pos++);
    pos++;
    for(; str[pos + i] != NULL; i++);
    buf = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++)
        buf[j] = malloc(sizeof(char) * (my_strlen(str[j + pos]) + 1));
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < my_strlen(str[j + pos]); k++)
            buf[j][k] = str[j + pos][k];
    }
    return buf;
}