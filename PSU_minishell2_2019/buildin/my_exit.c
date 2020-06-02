/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_exit.c
*/

#include "../src/shell.h"

void my_exit(char **command)
{
    int nbr;

    if (command[1] != NULL) {
        nbr = my_atoi(command[1]);
    } else {
        nbr = 0;
    }
    write(1, "exit\n", 6);
    exit(nbr);
}