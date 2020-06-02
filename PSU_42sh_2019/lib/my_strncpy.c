/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;
    int char_rank;

    while (src[count] != '\0')
        count++;
    for (char_rank = 0; char_rank < n; char_rank++)
        dest[char_rank] = src[char_rank];
    if (n > count)
        dest[n] = '\0';
    return (dest);
}
