/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** Reverses a string
*/

#include "firebolt.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char str_copy = 0;

    while (i < len / 2 + 1) {
        str_copy = str[len - i];
        str[len - i] = str[i];
        str[i] = str_copy;
        i ++;
    }
    return (str);
}
