/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd.c
*/

#include "../src/shell.h"

int other_case_cd(char **cmd, struct s_shell *shell)
{
    int amnt_param = my_countword(cmd);

    if (amnt_param > 2) {
        write(1, "cd: too many arguments\n", 24);
        exit(84);
    }
    if (amnt_param == 1 || cmd[1][0] == '~') {
        chdir("/home");
        return 1;
    }
    else
        return 0;
}

void my_cd(char **cmd, struct s_shell *shell)
{
    if (other_case_cd(cmd, shell) == 0)
    if (cmd[1][0] == '-') {
        chdir(shell->prev_pwd);
        shell->prev_pwd = malloc(my_strlen(shell->current_pwd) + 1);
        for (int i = 0; i < my_strlen(shell->current_pwd); i++)
            shell->prev_pwd[i] = shell->current_pwd[i];
        shell->prev_pwd[my_strlen(shell->current_pwd)] = '\0';
    }
    else if (chdir(cmd[1]) == 0) {
        shell->prev_pwd = malloc(my_strlen(shell->current_pwd) + 1);
        for (int i = 0; i < my_strlen(shell->current_pwd); i++)
            shell->prev_pwd[i] = shell->current_pwd[i];
        shell->prev_pwd[my_strlen(shell->current_pwd)] = '\0';
    }
    else
        perror("cd");
}