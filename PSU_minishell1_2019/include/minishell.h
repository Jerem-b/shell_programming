/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell.h
*/
#ifndef _MINISHELL_
#define _MINISHELL_
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
    char **env_cpy;
    int line_env;
    char **command;
    int amnt_param;
    char *current_dir;
    char *prev_dir;
} t_shell;
void cpy_env(struct s_shell *shell, char **env);
int my_strlen(char *str);
void get_command(struct s_shell *shell, char *str);
void fill_command(struct s_shell *shell, int nbr_word, char *str, int len_word);
void get_pwd(struct s_shell *shell);
void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
void switch_command(struct s_shell *shell, char **env);
void my_env(char **env, struct s_shell *shell);
int my_exit(struct s_shell *shell);
int my_atoi(char *str);
void my_cd(struct s_shell *shell);
void change_path_env(struct s_shell *shell);
void my_setenv(struct s_shell *shell);
void my_unsetenv(struct s_shell *shell);
void build_in_command(struct s_shell *shell);
#endif