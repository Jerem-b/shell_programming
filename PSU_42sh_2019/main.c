/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main file for mysh
*/

#include "mysh.h"

int main(int ac, char **av, char **envp)
{
    shell_vars_t sh_vars = {ac, av, NULL, NULL, NULL, NULL, 0};

    if (ac < 1)
        return (84);
    sh_vars.envp = arr2dup(envp);
    sh_vars.path = update_path(sh_vars.envp);
    if (ac == 1)
        return (free_sh_vars_ret(i_mode(&sh_vars), sh_vars));
    if (ac > 1)
        return (free_sh_vars_ret(ni_mode(&sh_vars), sh_vars));
    return (0);
}
