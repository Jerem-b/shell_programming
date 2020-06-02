/*
** EPITECH PROJECT, 2019
** command_checking.c
** File description:
** Check command before storage
*/

#include "mysh.h"

static int last_check(char *str, int len)
{
    int test = 0;

    for (int i = 1; i < len; i++) {
        if (is_sep(str[i - 1]) == 0 && is_sep(str[i]) == 84) {
            test = i;
            while (str[i] == ' ')
                i++;
            if (i != test && is_sep(str[i]) == 0)
                return (84);
            test = 0;
        }
    }
    return (0);
}

static int check_double(char *str, int rank)
{
    if (str[rank] == '>' && str[rank + 1] == '>')
        return (0);
    if (str[rank] == '<' && str[rank + 1] == '<')
        return (0);
    if (str[rank] == '&' && str[rank + 1] == '&')
        return (0);
    if (str[rank] == '|' && str[rank + 1] == '|')
        return (0);
    return (84);
}

static int continue_checking(char *str, int len)
{
    int sep_len = 0;
    int code = 0;

    for (int i = 0; i < len; i++) {
        if (is_sep(str[i]) == 0) {
            sep_len++;
            continue;
        }
        code = (sep_len == 1 && str[i - 1] == '&') ? 84 : 0;
        if (sep_len > 1 && code != 84) {
            if (sep_len == 2)
                code = check_double(str, i - 2);
            else
                return (84);
        }
        if (code == 84)
            return (84);
        sep_len = 0;
        code = 0;
    }
    return (last_check(str, len));
}

int command_checking(char *str)
{
    int len = my_strlen(str);
    int i = 0;

    while (str[i] == ' ' && str[i] != 0)
        i++;
    if (i == len)
        return (84);
    if (is_sep(str[i]) == 0)
        return (84);
    i = len - 1;
    while (str[i] == ' ')
        i--;
    if (is_sep(str[i]) == 0)
        return (84);
    return (continue_checking(str, len));
}
