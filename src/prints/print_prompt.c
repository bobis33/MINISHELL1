/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** print
*/

#include <unistd.h>
#include <stdlib.h>

#include "lib.h"
#include "utils.h"
#include "struct.h"
#include "macro.h"


static int log_or_host(env_t *env, int i)
{
    char *log = NULL;
    char *host = NULL;
    if (my_strncmp(env->env[i], "LOGNAME=", 8) == 0) {
        log = parse_env(env->env[i] + 8);
        if (write(1, log, my_strlen(log) - 1) == -1
        || write(1, "@", 1) == -1)
            return FAILURE;
    }
    if (my_strncmp(env->env[i], "HOSTNAME=", 9) == 0) {
        host = parse_env(env->env[i] + 9);
        if (write(1, host, my_strlen(host) - 1) == -1
        || write(1, " ", 1) == -1)
            return FAILURE;
    }
    free(log);
    free(host);
    return SUCCESS;
}

static int print_pwd(char *pwd, int nb_slash)
{
    int k = 0;
    int i = 0;

    for (; i < nb_slash; k++) {
        if (pwd[k] == '/')
            i++;
    }
    for (; pwd[k] != '\0'; k++)
        if (write(1, &pwd[k], 1) == -1)
            return FAILURE;
    if (write(1, "}~ $> ", 6) == -1)
        return FAILURE;
    return SUCCESS;
}

static int nb_slash(char *pwd)
{
    int nb = 0;

    for (int i = 0; pwd[i] != '\0'; i++) {
        if (pwd[i] == '/')
            nb++;
    }
    return nb;
}

int print_prompt(env_t *env)
{
    char *pwd = getcwd(NULL, 0);
    int nb_s = nb_slash(pwd);

    if (write(1,"~{ [MƗNƗSH3LL] ", 17) == -1)
        return FAILURE;
    for (int i = 0; env->env[i] != NULL; i++) {
        if (log_or_host(env, i) == FAILURE)
            return FAILURE;
    }
    if (print_pwd(pwd, nb_s) == FAILURE)
        return FAILURE;
    free(pwd);
    return SUCCESS;
}
