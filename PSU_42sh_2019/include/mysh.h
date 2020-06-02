/*
** EPITECH PROJECT, 2019
** mysh.h
** File description:
** Header file for mysh
*/

#ifndef _MYSH_H_
#define _MYSH_H_

#define UNUSED __attribute__((unused))
#define PIPE 4096

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "firebolt.h"

typedef struct pip
{
    int end;
    int fd[2];
    char buff[PIPE];
    int saved_stdin;
    int saved_stdout;
} pip_t;

typedef struct shell_vars
{
    int ac;
    char **av;
    char **envp;
    char ***commands;
    char **path;
    char *shell_red;
    int n_com;
} shell_vars_t;

int arr2free_ret(int nb, char **arr);
int arrfree_ret(int nb, char *arr);
int my_write_ret(int nb, char const *str, int fd);
int arr3free(char ***arr);
int free_sh_vars_ret(int nb, shell_vars_t sh_vars);
int i_mode(shell_vars_t *vars);
int ni_mode(shell_vars_t *vars);
int is_sep(char c);
char *concat_ni_commands(int ac, char **av);
int command_parsing(char *str, shell_vars_t *vars, int test);
int command_checking(char *str);
int prompt(char **envp);
char *find_env_data(char **envp, char const *str);
char *env_data(char **envp, int rank);
int find_in_env(char **envp, char const *str);
char **update_path(char **envp);
int is_built_in(char *str);
int launch(shell_vars_t *vars);
int can_be_exec(shell_vars_t *vars, int i);
int exec_internals(shell_vars_t *vars, int *rk, pip_t *pipes);
int exec_externals(shell_vars_t *vars, int *rk, pip_t *pipes);
int error_ret(int code, char *str, int nb);
int m_ret_e(int code, char *str, char const *reason);
int update_var_env(char ***envp, char const *var, char const *content);
int check_alpha(char const *str);

int exec_env(shell_vars_t UNUSED *vars, int UNUSED rk);
int exec_exit(shell_vars_t *vars, int rk);
int exec_cd(shell_vars_t *vars, int rk);
int exec_setenv(shell_vars_t *vars, int rk);
int exec_unsetenv(shell_vars_t *vars, int rk);
int exec_echo(shell_vars_t *var, int rk);

int ret_closefd(int nb, pip_t pipes);
int redir_out(int *rk, shell_vars_t *vars);
int do_redirout(int *pipe_fd, char *filename, int *rk, shell_vars_t *vars);
int i_rd(char sep);
int redirect(char sep, shell_vars_t *vars, int *rk, pip_t pipes);

int redir_out_append(int *rk, shell_vars_t *vars);
int do_redirout_app(int *pipe_fd, char *filename, int *rk, shell_vars_t *vars);
int redir_pipe(int *rk, shell_vars_t *vars);
int redir_in(int *rk, shell_vars_t *vars);

#endif
