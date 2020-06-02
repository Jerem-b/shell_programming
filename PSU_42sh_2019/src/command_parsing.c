/*
** EPITECH PROJECT, 2019
** command_parsing.c
** File description:
** command_parsing
*/

#include "mysh.h"

static int fill_sep(char **str, char c, int test, int *check)
{
    char tmp[2] = {0};

    tmp[0] = c;
    *str = concat_words(1, *str, tmp, NULL);
    if (test == 1)
        *check = 1;
    return (1);
}

static char *my_strdup_from_to(char *str, int start, int end)
{
    char *new_str = my_alloc_n_elem_zeroes(end - start);
    int rank = 0;

    for (int i = start; i < end; i++, rank++)
        new_str[rank] = str[i];
    return (new_str);
}

static int fill_commands(char *str, char **place, int *save)
{
    int start = 0;

    while (is_sep(str[*save]) != 84 && str[*save] != 0)
        (*save)++;
    start = *save;
    while (is_sep(str[*save]) == 84 && str[*save] != 0)
        (*save)++;
    *place = my_strdup_from_to(str, start, *save);
    return (0);
}

static int count_separators(char *str, char **sep_com)
{
    int sep = 0;
    int len = my_strlen(str);
    int check = 0;

    for (int i = 0; i < len - 1; i++) {
        if (is_sep(str[i]) != 84) {
            if (str[i] == '>' && str[i + 1] == '>')
                i += fill_sep(sep_com, 'a', 1, &check);
            if (str[i] == '<' && str[i + 1] == '<')
                i += fill_sep(sep_com, 'b', 1, &check);
            if (str[i] == '|' && str[i + 1] == '|')
                i += fill_sep(sep_com, 'c', 1, &check);
            if (str[i] == '&' && str[i + 1] == '&')
                i += fill_sep(sep_com, 'd', 1, &check);
            (check == 0) ? fill_sep(sep_com, str[i], 0, &check) : 0;
            sep++;
        }
        check = 0;
    }
    return (sep);
}

int command_parsing(char *str, shell_vars_t *vars, int test)
{
    char **tmp = NULL;
    int save = 0;

    vars->n_com = count_separators(str, &vars->shell_red) + 1;
    tmp = arr2alloc(vars->n_com);
    for (int i = 0; i < vars->n_com; i++)
        fill_commands(str, &tmp[i], &save);
    vars->commands = malloc((vars->n_com + 1) * sizeof(char **));
    for (int i = 0; i < vars->n_com; i++)
        vars->commands[i] = str_word_arr_delim(tmp[i], ' ');
    vars->commands[vars->n_com] = NULL;
    arr2free(tmp);
    (test == 1) ? free(str) : 0;
    return (0);
}
