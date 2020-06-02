/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** transform_string.c
*/

#include "../src/shell.h"

char *transform_string(char **command)
{
    char *buf = malloc(sizeof(char) * 300);

    if (command[0][0] == '/' && command[0][1] == 'b' && command[0][2] == 'i' && 
    command[0][3] == 'n' && command[0][4] == '/')
        return command[0];
    else {
        buf[0] = '/';
        buf[1] = 'b';
        buf[2] = 'i';
        buf[3] = 'n';
        buf[4] = '/';
        for (int i = 0; i < my_strlen(command[0]); i++)
            buf[i + 5] = command[0][i];
        buf[my_strlen(command[0]) + 5] = '\0';
        return buf;
    }  
}