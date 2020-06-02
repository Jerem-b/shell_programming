/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** transform_string_cmd.c
*/

#include "../src/shell.h"

char **transform_string_cmd(char **cmd, char *separator)
{
    char **buffer;
    int i = 0;
    int j = 0;

    for(; my_strcmp(cmd[i], separator) != 0; i++);
    buffer = malloc(sizeof(char *) * (i + 1));
    for (; j < i; j++)
        buffer[j] = malloc(sizeof(char) * (my_strlen(cmd[j]) + 1));
    for (int k = 0; k < i; k++) {
        for (int l = 0; cmd[k][l] != '\0'; l++)
            buffer[k][l] = cmd[k][l];
    }
    buffer[i] = NULL;
    return buffer;
}