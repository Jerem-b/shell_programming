/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** redirection.c
*/

#include "../src/shell.h"

void redirection(char **cmd, char **av, char **env, struct s_shell *shell)
{    
    for (int pos = 0; cmd[pos] != NULL; pos++) {
        if (my_strcmp(">", cmd[pos]) == 0) {
            redir_in(cmd, env);
            break;
        }
        if (my_strcmp("<", cmd[pos]) == 0) {
            redir_out(cmd, env);
            break;
        }
        if (my_strcmp(">>", cmd[pos]) == 0) {
            redir_in_append(cmd, env);
            break;
        }
        if (my_strcmp("<<", cmd[pos]) == 0) {
            break;
        }
        if (my_strcmp("|", cmd[pos]) == 0) {
            my_pipe(cmd, av, env);
            break;
        }
    }
}