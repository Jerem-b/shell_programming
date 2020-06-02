/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_atoi.c
*/

#include "../include/minishell.h"

int my_atoi(char *str)
{
    int result = 0;
    int k = 0;

    if (str[0] == '-')
        k++;
    for (; str[k] != '\0' && str[k] != '\n'; k++)
        result = result * 10 + str[k] - '0';
    if (str[0] == '-')
        result *= -1;
    return result;
}
