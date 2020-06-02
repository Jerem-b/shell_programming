/*
** EPITECH PROJECT, 2019
** check_alpha.c
** File description:
** check_alpha
*/

#include "mysh.h"

int check_alpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!((str[i] >= '0' && str[i] <= '9')
            || (str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] == '_')))
            return (84);
    return (0);
}
