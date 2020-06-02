/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen
*/

#include "firebolt.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    while (str[i])
        i++;
    return (i);
}
