/*
** EPITECH PROJECT, 2019
** arr2disp.c
** File description:
** arr2disp
*/

#include "firebolt.h"

int arr2disp(char **arr, int check)
{
    int len = arr2len(arr);

    if (check != 2 && check != 3) {
        for (int i = 0; i < (len - 1); i++) {
            my_write(1, arr[i]);
            my_write(1, "\n");
        }
    } else
        for (int i = 0; i < (len - 1); i++)
            my_write(1, arr[i]);
    my_write(1, arr[len - 1]);
    if (check == 0 || check == 2)
        my_write(1, "\n");
    return (0);
}
