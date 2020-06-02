/*
** EPITECH PROJECT, 2019
** concat_words.c
** File description:
** Concat words
*/

#include "firebolt.h"

char *concat_words(int check, char *str, ...)
{
    va_list list;
    char *tmp = NULL;
    char *new_str = NULL;
    int len = my_strlen(str);
    int f_rank = len;

    va_start(list, str);
    while ((tmp = va_arg(list, char *)))
        len += my_strlen(tmp);
    va_end(list);
    new_str = my_alloc_n_elem_zeroes(len);
    if (str != NULL)
        my_strcpy(new_str, str);
    va_start(list, str);
    while ((tmp = va_arg(list, char *)))
        for (int i = 0; tmp[i]; i++, f_rank++)
            new_str[f_rank] = tmp[i];
    va_end(list);
    if (check == 1 && str != NULL)
        free(str);
    return (new_str);
}
