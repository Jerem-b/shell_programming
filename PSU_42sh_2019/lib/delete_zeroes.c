/*
** EPITECH PROJECT, 2019
** delete_zeroes
** File description:
** delete_zeroes
*/

#include "firebolt.h"

int zero_size(char *str)
{
    int count_zeroes = 0;

    if (str[0] == '-') {
        str = str + 1;
    }
    if (str[0] == '0') {
        while (str[count_zeroes] == '0') {
            count_zeroes++;
        }
    }
    return (count_zeroes);
}

char *delete_zeroes(char *str)
{
    int count_zeroes = zero_size(str);
    int size = my_strlen(str) + 1;
    char *arr;
    int counter = 0;
    int boolean = 0;
    int i = 0;

    arr = malloc(size - count_zeroes);
    while (str[counter] != '\0') {
        if ((str[counter] == '0') && (boolean == 0)) {
            counter = counter + count_zeroes;
            boolean = 1;
        }
        arr[i] = str[counter];
        counter++;
        i++;
    }
    arr[i] = '\0';
    return (arr);
}
