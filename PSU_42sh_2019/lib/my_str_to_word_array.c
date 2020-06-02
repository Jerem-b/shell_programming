/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "firebolt.h"

int count_words(char *str)
{
    int i = 0;
    int count = 0;

    if (my_strlen(str) == 0)
        return (-1);
    while (1) {
        if (str[i] != 32 && (str[i + 1] == 32 || str[i + 1] == 0))
            count++;
        i++;
        if (str[i] == 0)
            break;
    }
    return (count);
}

void fill_double_arr(char **arr, char *str, int w_count)
{
    int cn = 0;
    int rank = 0;
    int save = 0;

    for (int i = 0; i < w_count; i++) {
        while (str[cn] == 32)
            cn++;
        save = cn;
        for (;str[cn] != 32 && str[cn] != 0; cn++)
            rank++;
        arr[i] = malloc((rank + 1) * sizeof(char));
        rank = 0;
        while (str[save] != 32 && str[save] != 0) {
            arr[i][rank] = str[save];
            str[save] = 32;
            rank++;
            save++;
        }
        arr[i][rank] = 0;
        rank = 0;
    }
}

char **my_str_to_word_array(char *s)
{
    int w_count = count_words(s);
    char *str = NULL;
    char **arr = NULL;

    if (w_count == -1)
        return (NULL);
    str = my_alloc_n_elem_zeroes(my_strlen(s));
    my_strcpy(str, s);
    arr = malloc((w_count + 1) * sizeof(char *));
    fill_double_arr(arr, str, w_count);
    arr[w_count] = NULL;
    free(str);
    return (arr);
}
