/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** calc_amount.c
*/

#include "../src/shell.h"

int calc_amount(char *str, char delim)
{
    int amnt = 1;
    for (int j = 0; j < my_strlen(str); j++)
        if (str[j] == delim)
            amnt++;
    return amnt;
}