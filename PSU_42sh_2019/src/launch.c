/*
** EPITECH PROJECT, 2019
** launch.c
** File description:
** Start the inline command loop
*/

#include "mysh.h"

int ret_closefd(int nb, pip_t pipes)
{
    dup2(pipes.saved_stdin, 0);
    dup2(pipes.saved_stdout, 1);
    close(pipes.saved_stdin);
    close(pipes.saved_stdout);
    close(pipes.fd[0]);
    close(pipes.fd[1]);
    return nb;
}

int ret(shell_vars_t *vars, int *i, pip_t pipes)
{
    int code = 0;

    if (vars->shell_red != 0 && i_rd(vars->shell_red[*i]) == 0 &&
    vars->n_com > 1) {
        code = redirect(vars->shell_red[*i], vars, i, pipes);
        return code;
    } else
        return exec_externals(vars, i, &pipes);
    return code;
}

int launch(shell_vars_t *vars)
{
    int code = 0;
    pip_t pipes = {0};

    pipes.saved_stdin = dup(0);
    pipes.saved_stdout = dup(1);
    if (pipe(pipes.fd) == -1)
        return (84);
    for (int i = 0; i < vars->n_com; i++) {
        if (is_built_in(vars->commands[i][0]) == 0) {
            code = exec_internals(vars, &i, &pipes);
            continue;
        }
        else if (can_be_exec(vars, i) == 0) {
            if (ret(vars, &i, pipes) == -1)
                i++;
        }
    }
    return (ret_closefd(code, pipes));
}
