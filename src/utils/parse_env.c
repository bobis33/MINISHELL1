/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-elliot.masina
** File description:
** parse_env
*/

#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "struct.h"

char *parse_env(char *env)
{
    char *tmp = NULL;
    int j = 0;
    tmp = malloc(sizeof(char) + (my_strlen(env) + 2));
    for (int i = 0; env[i] != '\0' && env[i] != '\n'; i++) {
        tmp[j] = env[i];
        j++;
    }
    tmp[j] = '/';
    j++;
    tmp[j] = '\0';
    return tmp;
}
