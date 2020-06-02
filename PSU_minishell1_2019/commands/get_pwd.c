/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** get_pwd.c
*/

#include "../include/minishell.h"

void get_pwd(struct s_shell *shell)
{
    char *buff = malloc(sizeof(char) * (300 + 1));
    size_t size = 300;
    int i = 0;

    shell->current_dir = 0;
    getcwd(buff, size);
    shell->current_dir = malloc(sizeof(char) * 301);
    for (; buff[i] != '\0'; i++)
        shell->current_dir[i] = buff[i];
    shell->current_dir[i] = '\0';
}