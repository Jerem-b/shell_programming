/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** check_redir.c
*/

#include "../src/shell.h"

int check_redir(char **cmd, struct s_shell *shell)
{
    for (int i = 0; i < my_countword(cmd); i++) {
        for (int j = 0; j < my_strlen(cmd[i]); j++) {
            if (cmd[i][j] == '>' || cmd[i][j] == '<' || cmd[i][j] == '|') {
                return 0;
            }
        }
    }
    return 1;
}