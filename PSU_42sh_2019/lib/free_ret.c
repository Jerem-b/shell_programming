/*
** EPITECH PROJECT, 2019
** free_ret.c
** File description:
** free and return
*/

#include "firebolt.h"

int free_ret(int code, char *str)
{
    free(str);
    return (code);
}
