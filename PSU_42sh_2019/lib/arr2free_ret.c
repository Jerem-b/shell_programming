/*
** EPITECH PROJECT, 2019
** arr2free_ret.c
** File description:
** Free arr2 and ret
*/

#include "firebolt.h"

int arr2free_ret(int code, char **arr)
{
    arr2free(arr);
    return (code);
}
