/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** input
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "utils.h"
#include "lib.h"


static void transform_input(env_t *env)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) + (my_strlen(env->tmp) + 1));
    my_strcpy(tmp, env->tmp);
    char *token = strtok(tmp, " \t");

    malloc_input(env);
    env->tmp[my_strlen(env->tmp) - 1] = '\0';
    my_strcpy(tmp, env->tmp);
    for (int j = 0; token != NULL; j++)
        token = strtok(NULL, " \t");
    token = strtok(env->tmp, " \t");
    for (; token != NULL; i++) {
        my_strcpy(env->cmd[i], token);
        token = strtok(NULL, " \t");
    }
    env->cmd[i] = NULL;
}

void copy_input(env_t *env, char *buf)
{
    int i = 0;
    int j = 0;
    env->passed = 1;

    for (; buf[i] == '\t' || buf[i] == ' '; i++);

    for (; buf[i] != '\0'; i++) {
        env->tmp[j] = buf[i];
        j++;
    }
    env->tmp[j] = '\0';
    transform_input(env);
}
