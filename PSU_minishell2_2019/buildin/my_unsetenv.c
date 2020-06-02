/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_unsetenv.c
*/

#include "../src/shell.h"

void my_unsetenv(void)
{
    write(1, "unsetenv\n", 8);
}