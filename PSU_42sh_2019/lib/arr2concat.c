/*
** EPITECH PROJECT, 2019
** arr2concat.c
** File description:
** arr2concat
*/

#include "firebolt.h"

char **arr2concat(char **arr, int fe, char *str, ...)
{
    va_list list;
    char **arr2new = NULL;
    char *tmp;
    int d2len = arr2len(arr);
    int len = 1;

    va_start(list, str);
    while (va_arg(list, char *))
        len++;
    va_end(list);
    arr2new = arr2alloc(d2len + len);
    arr2cpy(arr2new, arr);
    va_start(list, str);
    arr2new[d2len++] = my_strdup(str);
    while ((tmp = va_arg(list, char *)))
        arr2new[d2len++] = my_strdup(tmp);
    va_end(list);
    if (fe == 1 && arr != NULL)
        arr2free(arr);
    return (arr2new);
}
