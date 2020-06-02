/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** shell.h
*/

#ifndef _SHELL_
#define _SHELL_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>

typedef struct s_shell
{
    char **copy_env;
    int env_h;
    char **paths;
    int amnt_paths;
    char ***com;
    int amnt_cmd;
    char *current_pwd;
    char *prev_pwd;
} t_shell;
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
int my_atoi(char *str);
void cpy_env(struct s_shell *shell, char **env);
char **fill_buffer(int amnt, char *str, char **dest, char delim);
int calc_amount(char *str, char delim);
char **my_strtok_struct(char *str, const char delim, struct s_shell *shell);
void get_paths(struct s_shell *shell);
char *get_oldpwd(char *oldpwd);
void get_pwd(struct s_shell * shell);
void my_free(struct s_shell *shell);
char ***mal_amnt_cmd(char ***dest, struct s_shell *shell, char *buffer);
char ***mal_amntword(struct s_shell *shell, char *buffer, int pos, char ***dest, int nb_word);
char ***mal_lenword(struct s_shell *shell, int nb_word, char ***dest, char *b);
char ***fill_cmd(struct s_shell *shell, int nb_word, char *b, char ***dest);
char ***make_com(char *buffer, struct s_shell *shell);
int my_countword(char **str);
int other_case_cd(char **cmd, struct s_shell *shell);
void my_cd(char **cmd, struct s_shell *shell);
void my_env(struct s_shell *shell);
void my_exit(char **command);
void my_setenv(void);
void my_unsetenv(void);
int check_buildin(char **command, struct s_shell *shell);
int other_case(char **command, struct s_shell *shell);
char *transform_string(char **command);
void execute_command(char **command, char **av, char **env);
int check_redir(char **cmd, struct s_shell *shell);
char **transform_string_cmd(char **cmd, char *separator);
char **transform_string_other(char **str, char *separator);
void redirection(char **cmd, char **av, char **env, struct s_shell *shell);
void redir_out(char **cmd, char **env);
void my_pipe(char *cmd[], char *av[], char *env[]);
void other_pipe(int *pipe_fd, char **env, char **cmd, int i);
void redir_in_append(char **cmd, char **env);
void other_append(int *pipe_fd, char **cmd, char **env, int ret);
void redir_in(char **cmd, char **env);
void other_in(int *pipe_fd, char **cmd, char **env, int ret);
#endif