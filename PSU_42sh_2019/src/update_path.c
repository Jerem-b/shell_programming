/*
** EPITECH PROJECT, 2019
** update_path.c
** File description:
** Update the path with the env
*/

#include "mysh.h"

char **update_path(char **envp)
{
    char *str = find_env_data(envp, "PATH");
    char **path = NULL;
    int len = 0;

    if (my_strcmp(str, "mysh") == 0) {
        free(str);
        return (NULL);
    }
    path = str_word_arr_delim(str, ':');
    len = arr2len(path);
    for (int i = 0; i < len; i++)
        path[i] = concat_words(1, path[i], "/", NULL);
    free(str);
    return (path);
}
