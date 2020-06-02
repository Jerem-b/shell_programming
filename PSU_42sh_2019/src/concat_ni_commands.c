/*
** EPITECH PROJECT, 2019
** concat_ni_commands
** File description:
** Concat av entry
*/

#include "mysh.h"

char *concat_ni_commands(int ac, char **av)
{
    char *commands = NULL;

    for (int i = 1; i < ac; i++)
        commands = concat_words(1, commands, av[i], NULL);
    return (commands);
}
