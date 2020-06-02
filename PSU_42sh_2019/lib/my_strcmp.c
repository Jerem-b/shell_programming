/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** Compares 2 strings and returns a value based off comparison
*/

#include "firebolt.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    return (0);
}
