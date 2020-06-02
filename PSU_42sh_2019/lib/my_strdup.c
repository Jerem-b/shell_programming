/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Copy string into a new allocated one
*/

#include "firebolt.h"

char *my_strdup(char const *str)
{
    char *new_str = my_alloc_n_elem_zeroes(my_strlen(str));

    my_strcpy(new_str, str);
    return (new_str);
}
