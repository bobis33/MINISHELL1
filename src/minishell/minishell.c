/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** minishell
*/

#include <stdlib.h>

#include "lib.h"
#include "macro.h"
#include "struct.h"
#include "print.h"
#include "utils.h"
#include "mysh.h"


static int call_child_process(env_t *env)
{
    if (env->cmd[0] != NULL && builtins(env) != 1) {
        if (child_process(env) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int minishell_init(char *envp[])
{
    env_t *env = malloc(sizeof(env_t));
    env->tmp = malloc(sizeof(char) * (100));
    env->path = NULL;
    env->passed = 0;

    if (copy_env(envp, env) == FAILURE)
        return FAILURE;
    handle_path(env);
    while (1) {
        if (print_prompt(env) == FAILURE
        || handle_line(env) == FAILURE
        || call_child_process(env) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
