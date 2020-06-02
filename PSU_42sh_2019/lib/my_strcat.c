/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include "firebolt.h"

char *my_strcat(char *dest, char const *src)
{
    int src_len = my_strlen(src);
    int dest_len = my_strlen(dest);

    for (int i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    return (dest);
}
