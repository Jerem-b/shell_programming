/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** my_strncat
*/

#include "firebolt.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int src_len = my_strlen(src);
    int dest_len = my_strlen(dest);

    for (int i = 0; i < nb; i++) {
        dest[dest_len + i] = src[i];
    }
    if (nb > src_len) {
        dest[src_len + dest_len] = '\0';
    }
    return (dest);
}
