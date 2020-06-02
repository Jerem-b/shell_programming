/*
** EPITECH PROJECT, 2019
** pos_int_to_str.c
** File description:
** Place a positive int in a str
*/

#include "firebolt.h"

int num_len(int nb)
{
    int len = 1;
    int t = -1;

    while (t != 0) {
        t = nb / my_compute_power_rec(10, len);
        len++;
    }
    return (--len);
}

void compute(int nb, char *arr, int *rank)
{
    if (nb > 0) {
        compute(nb / 10, arr, rank);
        arr[*rank] = nb % 10 + 48;
        (*rank)++;
    }
}

char *pos_int_to_str(int nb)
{
    int len = num_len(nb);
    char *arr = my_alloc_n_elem_zeroes(len);
    int rank = 0;

    if (nb == 0) {
        arr[0] = 48;
        return (arr);
    }
    compute(nb, arr, &rank);
    return (arr);
}
