/*
** EPITECH PROJECT, 2019
** env_tools.c
** File description:
** Tools for env
*/

#include "mysh.h"

int find_in_env(char **envp, char const *str)
{
    int i = 0;
    int len = 0;

    if (envp == NULL)
        return (-1);
    while (envp[i]) {
        len = my_strlen(str);
        if (my_strncmp(envp[i], str, len) == 0 && envp[i][len] == '=')
            return (i);
        i++;
    }
    return (-1);
}

char *env_data(char **envp, int rank)
{
    int len = 0;
    char *output = NULL;
    int i = 0;

    if (envp == NULL)
        return (my_strdup("mysh"));
    len = my_strlen(envp[rank]);
    while (envp[rank][i] != '=')
        i++;
    i++;
    if (i == len)
        return (my_strdup("mysh"));
    output = my_alloc_n_elem_zeroes(len - i);
    for (int j = 0; i < len; j++, i++)
        output[j] = envp[rank][i];
    return (output);
}

char *find_env_data(char **envp, char const *str)
{
    int i = find_in_env(envp, str);

    if (i != -1)
        return (env_data(envp, i));
    return (my_strdup("mysh"));
}

int update_var_env(char ***envp, char const *var, char const *content)
{
    int i = find_in_env(*envp, var);

    if (i == -1) {
        *envp = arr2concat(*envp, 1, "Will always be replaced", NULL);
        i = arr2len(*envp) - 1;
    }
    free((*envp)[i]);
    (*envp)[i] = NULL;
    if (content != NULL)
        (*envp)[i] = concat_words(0, (*envp)[i], var, "=", content, NULL);
    else
        (*envp)[i] = concat_words(0, (*envp)[i], var, "=", NULL);
    return (0);
}
