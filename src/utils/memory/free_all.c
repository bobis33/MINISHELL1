/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** free_all
*/

#include <stdlib.h>
#include <stdio.h>

#include "struct.h"


static void free_array(env_t *env)
{
    for (int i = 0; env->env[i] != NULL; i++)
        free(env->env[i]);
    free(env->env);
    for (int i = 0; env->path[i] != NULL; i++)
        free(env->path[i]);
    free(env->path);
    for (int i = 0; env->cmd[i] != NULL; i++)
        free(env->cmd[i]);
    free(env->cmd);
}

void special_free(env_t *env)
{
    for (int i = 0; env->env[i] != NULL; i++)
        free(env->env[i]);
    free(env->env);
    for (int i = 0; env->path[i] != NULL; i++)
        free(env->path[i]);
    free(env->path);
    free(env->tmp);
    free(env);
}

void free_all(env_t *env)
{
    free_array(env);
    free(env->tmp);
    free(env);
}
