/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** Recursively returns a number to the power of argument p
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (result);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
