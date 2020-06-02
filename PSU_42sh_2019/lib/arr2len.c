/*
** EPITECH PROJECT, 2019
** arr2len.c
** File description:
** arr2len
*/

#include "firebolt.h"

int arr2len(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (i);
    while (arr[i])
        i++;
    return (i);
}
