/*
** EPITECH PROJECT, 2019
** replace_char.c
** File description:
** Replace char by another in a string
*/

#include "firebolt.h"

int replace_char(char *str, char to_rep, char rep, int test)
{
    int len = my_strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == to_rep) {
            str[i] = rep;
            if (test == 1)
                break;
        }
    }
    return (0);
}
