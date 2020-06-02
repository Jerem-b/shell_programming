/*
** EPITECH PROJECT, 2019
** arr2free.c
** File description:
** arr2free
*/

#include "firebolt.h"

int arr2free(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    while (arr[i])
        free(arr[i++]);
    free(arr);
    return (0);
}
