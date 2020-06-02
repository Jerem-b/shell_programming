/*
** EPITECH PROJECT, 2019
** my_alloc_n_elem_zeroes.c
** File description:
** Allocate array and malloc it
*/

#include "firebolt.h"

char *my_alloc_n_elem_zeroes(int n)
{
    char *arr = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < (n + 1); i++)
        arr[i] = 0;
    return (arr);
}
