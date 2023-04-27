/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** my_array_len
*/

#include <stddef.h>

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);

    return i;
}
