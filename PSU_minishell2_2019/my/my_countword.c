/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_countword.c
*/

#include "../src/shell.h"

int my_countword(char **str)
{
    int i = 0;

    for (; str[i] != NULL; i++);
    return i;
}