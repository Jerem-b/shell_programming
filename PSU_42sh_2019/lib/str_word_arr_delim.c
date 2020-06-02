/*
** EPITECH PROJECT, 2019
** str_word_arr_delim.c
** File description:
** str_to_word_array but with custom delim
*/

#include "firebolt.h"

static int check_str(char *str, char delim)
{
    int i = 0;

    if (str == NULL || my_strlen(str) == 0)
        return (84);
    while (str[i]) {
        if (str[i] != delim)
            return (0);
        i++;
    }
    return (84);
}

static int count_delim(char *str, char delim, int len)
{
    int sep = 0;
    int i = 0;

    while (str[i] == delim)
        i++;
    for (int j = len - 1; str[j] == delim; j--)
        str[j] = 0;
    for (; i < len; i++) {
        if (str[i] == delim) {
            sep++;
            while (str[i] == delim)
                i++;
        }
    }
    return (sep);
}

static int fill_words(char **dest, char *str, char delim, int *save)
{
    int start = 0;
    int rank = 0;

    while (str[*save] == delim && str[*save] != 0)
        (*save)++;
    start = *save;
    while (str[*save] != delim && str[*save] != 0)
        (*save)++;
    *dest = my_alloc_n_elem_zeroes(*save - start);
    for (int i = start; i < *save; i++, rank++)
        (*dest)[rank] = str[i];
    return (0);
}

char **str_word_arr_delim(char *string, char delim)
{
    char *str = NULL;
    char **arr = NULL;
    int arr_len = 1;
    int len = 0;
    int save = 0;

    if (check_str(string, delim) == 84)
        return (NULL);
    str = my_strdup(string);
    len = my_strlen(str);
    arr_len += count_delim(str, delim, len);
    arr = arr2alloc(arr_len);
    for (int i = 0; i < arr_len; i++)
        fill_words(&arr[i], str, delim, &save);
    free(str);
    return (arr);
}
