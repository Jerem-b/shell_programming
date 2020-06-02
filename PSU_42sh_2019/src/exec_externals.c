/*
** EPITECH PROJECT, 2019
** exec_externals.c
** File description:
** Exec external commands
*/

#include "mysh.h"

static int disp_if_error(int wstatus)
{
    int term = WTERMSIG(wstatus);

    if (term == SIGILL)
        my_write(2, "Illegal instruction");
    if (term == SIGABRT)
        my_write(2, "Abort");
    if (term == SIGSEGV)
        my_write(2, "Segmentation fault");
    if (term == SIGFPE)
        my_write(2, "Floating exception");
    if (WCOREDUMP(wstatus))
        my_write(2, " (core dumped)\n");
    else
        my_write(2, "\n");
    return (0);
}

int exec_externals(shell_vars_t *vars, int *rk, pip_t UNUSED *pipes)
{
    int code = 0;
    int wstatus = 0;
    pid_t child;
    pid_t wait;

    child = fork();
    if (child == -1)
        return (84);
    if (child == 0) {
        code = execve(vars->commands[*rk][0], vars->commands[*rk], vars->envp);
        if (code < 0)
            exit(m_ret_e(code, vars->commands[*rk][0],
                "Exec format error. Wrong Architecture"));
    } else {
        wait = waitpid(child, &wstatus, WUNTRACED | WCONTINUED);
        if (wait == -1)
            return (code);
        if (WIFSIGNALED(wstatus))
            disp_if_error(wstatus);
    }
    return (code);
}
