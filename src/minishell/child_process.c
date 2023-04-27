/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** child_process
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "macro.h"
#include "struct.h"
#include "lib.h"
#include "mysh.h"
#include "utils.h"
#include "print.h"


static int loop_execve(env_t *env)
{
    char *tmp = NULL;
    for (int i = 0; env->path[i] != NULL; i++) {
        tmp = malloc(sizeof(char) + 500);
        tmp = env->path[i];
        my_strcat(tmp, env->cmd[0]);
        if (execve(tmp, env->cmd, env->env) != -1) {
            free(tmp);
            exit(0);
        }
    }
    if (print_error(env->cmd) == FAILURE)
        return FAILURE;
    free(tmp);
    exit(0);
    return SUCCESS;
}

static int simple_execve(env_t *env)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(env->cmd[0]) + 1);
    for (; env->cmd[0][i] != '\n' && env->cmd[0][i] != '\0'; i++)
        tmp[i] = env->cmd[0][i];
    i++;
    tmp[i] = '\0';
    if (execve(tmp, env->cmd, env->env) != -1) {
        free(tmp);
        exit(0);
    }
    if (print_error(env->cmd) == FAILURE)
        return FAILURE;
    free(tmp);
    exit(0);
    return SUCCESS;
}

int child_process(env_t *env)
{
    int status = 0;
    int options = 0;
    int process_status = fork();
    int path_value = check_if_path(env);

    if (process_status == -1) {
        return FAILURE;
    } if (process_status == SUCCESS && path_value != 1) {
        if (loop_execve(env) == FAILURE)
            return FAILURE;
    } if (process_status == SUCCESS && path_value == 1) {
        if (simple_execve(env) == FAILURE)
            return FAILURE;
    } if (process_status != SUCCESS && process_status != -1) {
        if (waitpid(process_status, &status, options) == -1)
            return FAILURE;
        if (WIFSIGNALED(status) && print_segfault(status) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
