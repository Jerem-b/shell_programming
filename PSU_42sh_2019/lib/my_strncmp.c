/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** Compares 2 strings and returns a value based off comparison
*/

#include "firebolt.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n > my_strlen(s1) || n > my_strlen(s2))
        return (84);
    while (i < n) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    return (0);
}
