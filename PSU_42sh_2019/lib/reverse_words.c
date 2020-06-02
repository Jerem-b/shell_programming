/*
** EPITECH PROJECT, 2019
** reverse_words.c
** File description:
** reverse_words
*/

void reverse_words(char **arr, int count)
{
    char *tmp;
    int i = 0;

    count--;
    while (i < count) {
        tmp = arr[i];
        arr[i] = arr[count];
        arr[count] = tmp;
        i++;
        count--;
    }
}
