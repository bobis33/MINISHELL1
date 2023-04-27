/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** setenv
*/

#include <stddef.h>
#include <stdlib.h>

#include "lib.h"
#include "macro.h"
#include "print.h"


static int error_setenv(char const *name)
{
    if (((name[0] < 65 || name[0] > 90)
    && (name[0] < 97 || name[0] > 122))
    && name[0] != '_') {
        if (my_put_strerr(
        "setenv: Variable name must begin with a letter\n") == FAILURE)
            return FAILURE;
        return 1;
    } if (my_alphanum(name) == 1) {
        if (my_put_strerr(
        "setenv: Variable name must contain alphanumeric characters.\n")
        == FAILURE)
            return FAILURE;
        return 1;
    }
    return SUCCESS;
}

static int check_env_var(char **envp, char const *name)
{
    int value = 0;

    for (int i = 0; envp[i] != NULL; i++){
        if (my_strncmp(envp[i], name, my_strlen(name)) == SUCCESS) {
            value = i;
            return value;
        }
    }
    return value;
}

static int my_setenv(char **envp, char const *name, char *var)
{
    char *new_var = NULL;
    int size = my_array_len(envp);
    int check_var = check_env_var(envp, name);

    new_var = malloc(sizeof(char) * (my_strlen(name) + my_strlen(var) + 2));
    my_strcpy(new_var, name);
    my_strcat(new_var, "=");
    my_strcat(new_var, var);
    if (check_var != 0) {
        envp[check_var] = new_var;
    } else {
        envp[size] = new_var;
        envp[size + 1] = NULL;
    }
    return SUCCESS;
}

int built_setenv(char **envp, char **cmd)
{
    int return_value = 0;

    if (cmd[1] == NULL) {
        if (print_env(envp) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    if ((return_value = error_setenv(cmd[1])) == FAILURE)
        return FAILURE;
    if (return_value == 1)
        return SUCCESS;
    if (cmd[2] == NULL) {
        my_setenv(envp, cmd[1], "");
    } else {
        my_setenv(envp, cmd[1], cmd[2]);
    }
    return SUCCESS;
}
