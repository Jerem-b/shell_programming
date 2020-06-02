/*
** EPITECH PROJECT, 2019
** my_free.c
** File description:
** my_free
*/

#include "firebolt.h"

int my_free(int code, void **ptr, int type, int n)
{
    switch (type) {
        case (0): free(*ptr);
            break;
        case (1):
            for (int i = 0; ptr[i]; i++)
                free(ptr[i]);
            free(ptr);
            break;
        case (2):
            for (int i = 0; i < n; i++)
                free(ptr[i]);
            free(ptr);
            break;
    }
    return (code);
}
