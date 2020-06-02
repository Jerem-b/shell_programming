/*
** EPITECH PROJECT, 2019
** my_write.c
** File description:
** my_write
*/

#include "firebolt.h"

int my_write(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
    return (0);
}
