/*
** EPITECH PROJECT, 2019
** firebolt.h
** File description:
** Header file for libfirebolt
*/

#ifndef _FIREBOLT_H_
#define _FIREBOLT_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_write(int, char const *);
int my_strlen(char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char **my_str_to_word_array(char *);
char *my_alloc_n_elem_zeroes(int);
char *delete_zeroes(char *);
int is_number(char *);
int str_to_int(char *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char reverse_words(char **, int);
int my_put_nbr(int);
char *pos_int_to_str(int);
int my_compute_power_rec(int, int);
int arr2len(char **);
int arr2free(char **);
char *concat_words(int, char *, ...);
char **arr2dup(char **);
int arr2cpy(char **, char **);
char **arr2alloc(int);
char *my_strdup(char const *);
int arr2disp(char **, int);
char **arr2concat(char **, int, char *, ...);
int my_free(int, void **, int, int);
char **str_word_arr_delim(char *, char);
int replace_char(char *, char, char, int);
int free_ret(int code, char *str);
int arr2free_ret(int code, char **arr);

#endif
