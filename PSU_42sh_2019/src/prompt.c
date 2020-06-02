/*
** EPITECH PROJECT, 2019
** prompt.c
** File description:
** Display prompt
*/

#include "mysh.h"

int prompt(char **envp)
{
    char *who_am_i = find_env_data(envp, "LOGNAME");

    if (my_strcmp(who_am_i, "root") == 0)
        my_write(1, "#");
    else if (my_strcmp(who_am_i, "mysh") == 0)
        my_write(1, who_am_i);
    else
        my_write(1, "$");
    my_write(1, ">> ");
    free(who_am_i);
    return (0);
}
