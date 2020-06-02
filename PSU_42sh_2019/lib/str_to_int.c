/*
** EPITECH PROJECT, 2019
** number.c
** File description:
** number
*/

int len_size(char *a)
{
    int i = 0;

    while ((a[i] > 47) && (a[i] < 58)) {
        i++;
    }
    return (i);
}

int power(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    nb = nb * power(nb, p - 1);
    return (nb);
}

int str_to_int(char *str)
{
    int i = 0;
    int nb = 0;
    int boolean = 0;

    if (str[0] == '-') {
        str[0] = '0';
        boolean = 1;
    }
    while ((str[i] > 47) && (str[i] < 58)) {
        nb = nb + ((int) str[i] - 48) *
            power(10, (len_size(str) - i - 1));
        i++;
    }
    if (boolean == 1)
        nb *= (-1);
    return (nb);
}
