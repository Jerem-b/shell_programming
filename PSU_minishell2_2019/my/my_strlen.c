/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_strlen.c
*/

#include "../src/shell.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}