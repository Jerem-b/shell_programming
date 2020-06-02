/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/
#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    struct s_shell *shell = malloc(sizeof(struct s_shell) + 1);
    size_t size = 300;
    char *buffer = malloc(size);

    cpy_env(shell, env);
    while (1) {
        get_pwd(shell);
        my_putstr(shell->current_dir);
        my_putstr("> ");
        signal(SIGINT, SIG_IGN);
        if (getline(&buffer, &size, stdin) == EOF)
            break;
        get_command(shell, buffer);
        switch_command(shell, env);
    }
    write(1, "exit\n", 5);
    return 0;
}