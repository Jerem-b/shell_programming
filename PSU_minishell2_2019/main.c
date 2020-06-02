/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** main.c
*/

#include "src/shell.h"


void setup(int ac, char **av, char **env, struct s_shell *shell)
{
    cpy_env(shell, env);
    get_paths(shell);
}

void loop(struct s_shell *shell, char **av, char **env)
{
    char *buffer = malloc(sizeof(char) * 3001);
    size_t size = 3000;

    get_pwd(shell);
    write(1, shell->current_pwd, my_strlen(shell->current_pwd));
    write(1, "> ", 2);
    getline(&buffer, &size, stdin);
    shell->com = make_com(buffer, shell);
    for (int i = 0; i < shell->amnt_cmd; i++) {
        if (check_buildin(shell->com[i], shell) == 1 && 
        check_redir(shell->com[i], shell) == 1)
            execute_command(shell->com[i], av, env);
        else
            redirection(shell->com[i], av, env, shell);
    }
}

int main(int ac, char **av, char **env)
{
    struct s_shell *shell = malloc(sizeof(struct s_shell));

    setup(ac, av, env, shell);
    while (1)
        loop(shell, av, env);
    my_free(shell);
}