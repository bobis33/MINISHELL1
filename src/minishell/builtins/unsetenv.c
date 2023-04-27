/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** unsetenv
*/


#include <stddef.h>

#include "lib.h"
#include "struct.h"
#include "macro.h"


static void replace_env(char **envp, int i)
{
    for (; envp[i] != NULL; i++)
        envp[i] = envp[i + 1];
}

static void my_unsetenv(char **envp, char const *name)
{
    if (name == NULL)
        return;
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], name, my_strlen(name)) == 0) {
            replace_env(envp, i);
            return;
        }
    }
}

int built_unsetenv(char **envp, char *cmd)
{
    if (cmd == NULL) {
        if (my_put_strerr("unsetenv: Too few arguments.\n") == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    my_unsetenv(envp, cmd);
    return SUCCESS;
}
