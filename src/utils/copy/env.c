/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** env
*/

#include <stddef.h>
#include <stdlib.h>

#include "macro.h"
#include "struct.h"
#include "lib.h"

void fill_path(char **env, char **path, int i)
{
    int k = 0;
    int l = 0;

    for (int j = 5; env[i][j] != '\0'; j++) {
        if (env[i][j] == ':') {
            j++;
            path[k][l] = '/';
            l++;
            path[k][l] = '\n';
            k++;
            l = 0;
        }
        path[k][l] = env[i][j];
        l++;
    }
    path[k][l] = '/';
    l++;
    path[k][l] = '\n';
    k++;
    path[k] = NULL;
}

int copy_env(char *envp[], env_t *env)
{
    int i = 0;
    int nb_lines = 0;

    for (; envp[nb_lines] != NULL; nb_lines++);
    env->env = malloc(sizeof(char *) * (nb_lines + 2));
    if (env->env == NULL)
        return FAILURE;
    for (; envp[i] != NULL; i++) {
        env->env[i] = malloc(sizeof(char) * (my_strlen(envp[i]) + 200));
        if (env->env[i] == NULL)
            return FAILURE;
        my_strcpy(env->env[i], envp[i]);
    }
    env->env[i] = NULL;
    return SUCCESS;
}
