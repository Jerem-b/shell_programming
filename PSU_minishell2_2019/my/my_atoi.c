/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_atoi.c
*/

#include "../src/shell.h"

int my_atoi(char *str)
{
    int result = 0;
    int k = 0;

    if (str[0] == '-') {
        k++;
        result *= -1;
    }
    for (; str[k] != '\0' && str[k] != '\n'; k++)
        result = result * 10 + str[k] - '0';
    return result;
}