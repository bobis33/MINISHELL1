/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-elliot.masina
** File description:
** builtins
*/


#include "built.h"
#include "lib.h"
#include "macro.h"
#include "print.h"


int builtins(env_t *env)
{
    if (my_strcmp(env->cmd[0], "exit") == SUCCESS) {
        if (built_exit(env) == FAILURE) return FAILURE;
    } if (my_strcmp(env->cmd[0], "env") == SUCCESS) {
        if (print_env(env->env) == FAILURE) return FAILURE;
        return 1;
    } if (my_strcmp(env->cmd[0], "cd") == SUCCESS) {
        if (built_cd(env->env, env->cmd[1]) == FAILURE) return FAILURE;
        return 1;
    } if (my_strcmp(env->cmd[0], "setenv") == SUCCESS) {
        if (built_setenv(env->env, env->cmd) == FAILURE) return FAILURE;
        return 1;
    } if (my_strcmp(env->cmd[0], "unsetenv") == SUCCESS) {
        if (built_unsetenv(env->env, env->cmd[1]) == FAILURE) return FAILURE;
        return 1;
    }
    return SUCCESS;
}
