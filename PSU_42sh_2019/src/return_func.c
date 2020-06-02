/*
** EPITECH PROJECT, 2019
** return_func.c
** File description:
** Every return func
*/

#include "mysh.h"

int arr2free_ret(int nb, char **arr)
{
    arr2free(arr);
    return (nb);
}

int arrfree_ret(int nb, char *arr)
{
    free(arr);
    return (nb);
}

int my_write_ret(int nb, char const *str, int fd)
{
    my_write(fd, str);
    return (nb);
}

int arr3free(char ***arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    while (arr[i] != NULL)
        arr2free(arr[i++]);
    free(arr);
    return (0);
}

int free_sh_vars_ret(int nb, shell_vars_t sh_vars)
{
    arr2free(sh_vars.envp);
    arr2free(sh_vars.path);
    arr3free(sh_vars.commands);
    if (sh_vars.shell_red != NULL)
        free(sh_vars.shell_red);
    return (nb);
}
