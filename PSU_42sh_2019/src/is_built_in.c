/*
** EPITECH PROJECT, 2019
** is_built_in.c
** File description:
** Check if the command is a built_in
*/

#include "mysh.h"

int is_built_in(char *str)
{
    char *arr[] = {"env", "exit", "cd", "setenv", "unsetenv", "echo", NULL};

    for (int i = 0; arr[i]; i++)
        if (my_strcmp(arr[i], str) == 0)
            return (0);
    return (84);
}
