/*
** EPITECH PROJECT, 2019
** arr2alloc.c
** File description:
** arr2alloc
*/

#include "firebolt.h"

char **arr2alloc(int size)
{
    char **arr = malloc((size + 1) * sizeof(char *));

    for (int i = 0; i < (size + 1); i++)
        arr[i] = NULL;
    return (arr);
}
