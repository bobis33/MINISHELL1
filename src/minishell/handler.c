/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** handler_args
*/

#include <stdlib.h>
#include <stdio.h>

#include "lib.h"
#include "struct.h"
#include "macro.h"
#include "print.h"
#include "utils.h"


static int nb_lines(char *str)
{
    int lines = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':')
            lines++;
    }
    return lines;
}

void handle_path(env_t *env)
{
    for (int i = 0; env->env[i] != NULL; i++) {
        if (my_strncmp(env->env[i], "PATH=", 5) == 0) {
            malloc_path(env, nb_lines(env->env[i]));
            fill_path(env->env, env->path, i);
            return;
        }
    }
}

int handle_line(env_t *env)
{
    char *buf = NULL;
    size_t size = 0;
    ssize_t read_value = getline(&buf, &size, stdin);

    if (read_value == EOF) {
        if (print_exit() == FAILURE)
            return FAILURE;
        if (env->passed == 0) {
            special_free(env, buf);
        } else {
            free(buf);
            free_all(env);
        }
        exit(0);
    } if (read_value == -1)
        return FAILURE;
    copy_input(env, buf);
    free(buf);
    return SUCCESS;
}
