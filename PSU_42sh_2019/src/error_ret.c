/*
** EPITECH PROJECT, 2019
** error_ret.c
** File description:
** Return errors
*/

#include "mysh.h"

int error_ret(int code, char *str, int nb)
{
    if (str != NULL)
        my_write(2, str);
    my_write(2, ": ");
    if (nb != -1)
        my_write(2, strerror(nb));
    else
        my_write(2, strerror(errno));
    my_write(2, ".\n");
    return (code);
}

int m_ret_e(int code, char *str, char const *reason)
{
    if (str != NULL)
        my_write(2, str);
    my_write(2, ": ");
    my_write(2, reason);
    my_write(2, ".\n");
    return (code);
}
