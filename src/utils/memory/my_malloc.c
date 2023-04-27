/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** my_malloc
*/

#include <stdlib.h>

#include "lib.h"
#include "struct.h"

void malloc_path(env_t *env, int nb_lines)
{
    env->path = malloc(sizeof(char *) * (nb_lines + 1));
    for (int i = 0; i < nb_lines; i++)
        env->path[i] = malloc(sizeof(char) + 50);
}

void malloc_input(env_t *env)
{
    int nb_lines = 0;
    int j = 0;

    for (; env->tmp[nb_lines] != '\0'; nb_lines++);
    env->cmd = malloc(sizeof(char *) * (nb_lines + 2));
    for (int i = 0; env->tmp[i] != '\0'; i++) {
        env->cmd[j] = malloc(sizeof(char) + (my_strlen(env->tmp) + 8));
        j++;
    }
}
