/*
** EPITECH PROJECT, 2019
** is_sep
** File description:
** Is this char a separator
*/

#include "mysh.h"

int is_sep(char c)
{
    char sep[] = ";><|&";

    for (int i = 0; sep[i]; i++)
        if (c == sep[i])
            return (0);
    return (84);
}
