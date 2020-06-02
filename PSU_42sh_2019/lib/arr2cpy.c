/*
** EPITECH PROJECT, 2019
** arr2cpy.c
** File description:
** arr2cpy.c
*/

#include "firebolt.h"

int arr2cpy(char **dest, char **src)
{
    int len = arr2len(src);

    for (int i = 0; i < len; i++)
        dest[i] = my_strdup(src[i]);
    return (0);
}
