/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** mal_amnt_cmd.c
*/

#include "../src/shell.h"

char ***mal_amnt_cmd(char ***dest, struct s_shell *shell, char *buffer)
{
    shell->amnt_cmd = 1;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';')
            shell->amnt_cmd++;
    }
    dest = malloc(sizeof(char **) * (shell->amnt_cmd + 1));
    return dest;
}