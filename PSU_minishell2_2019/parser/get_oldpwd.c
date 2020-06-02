/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** get_oldpwd.c
*/

#include "../src/shell.h"

char *get_oldpwd(char *oldpwd)
{
    char* dest = malloc(sizeof(char) * (my_strlen(oldpwd) + 1));
    int i = 0;
    int pos = 0;

    for (; oldpwd[i] != '='; i++);
    i++;
    for (; oldpwd[i] != '\0'; i++) {
        dest[pos] = oldpwd[i];
        pos++;
    }
    dest[pos + 1] = '\0';
    return dest;
}