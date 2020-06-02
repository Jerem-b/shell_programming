/*
** EPITECH PROJECT, 2019
** arr2dup.c
** File description:
** arr2dup
*/

#include "firebolt.h"

char **arr2dup(char **arr)
{
    char **new_arr = arr2alloc(arr2len(arr));

    arr2cpy(new_arr, arr);
    return (new_arr);
}
