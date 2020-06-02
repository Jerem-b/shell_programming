/*
** EPITECH PROJECT, 2019
** is_number.c
** File description:
** is_number
*/

#include "firebolt.h"

int is_number(char *str)
{
    int len = my_strlen(str);
    int count = 0;

    if (len > 9)
        return (84);
    if (str[0] == '-')
        count++;
    for (int i = 0; i < len; i++)
        if (str[i] > 47 && str[i] < 58)
            count++;
    if (count == len)
        return (0);
    return (84);
}
