/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-elliot.masina
** File description:
** cd
*/

#include <unistd.h>
#include <stdlib.h>

#include "lib.h"
#include "macro.h"
#include "utils.h"
#include "print.h"


static int cd_home(char **envp)
{
    char *oldwd = getcwd(NULL, 0);
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "OLDPWD=", 7) == 0)
            my_strcpy(envp[i] + 7, oldwd);
        if (my_strncmp(envp[i], "HOME=", 5) == 0
        && chdir(parse_env(envp[i] + 5)) == -1)
            return FAILURE;
    }
    free(oldwd);
    return SUCCESS;
}

static int cd_oldwd(char **envp)
{
    int i = 0;
    char *path = malloc(sizeof(char) * (my_strlen(envp[i] + 7)));
    for (; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "OLDPWD=", 7) == 0) {
            path = parse_env(envp[i] + 7);
            chdir(path);
            free(path);
        }
    }
    return SUCCESS;
}

static int cd_folder(char *cmd)
{
    char *path = malloc(sizeof(char) + (my_strlen(cmd) + 1));
    my_strcpy(path, cmd);
    path[my_strlen(path) + 1] = '/';
    if (chdir(path) == -1) {
        if (print_cd(path) == FAILURE)
        return FAILURE;
    }
    free(path);
    return SUCCESS;
}

static int case_cd(char **envp, char *cmd)
{
    char *oldwd = getcwd(NULL, 0);

    if (cmd == NULL) {
        return cd_home(envp);
    } if (my_strcmp(cmd, "-") == SUCCESS) {
        if (cd_oldwd(envp) == FAILURE)
            return FAILURE;
    } else {
        if (cd_folder(cmd) == FAILURE)
            return FAILURE;
    }
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "OLDPWD=", 7) == 0)
            my_strcpy(envp[i] + 7, oldwd);
    }
    free(oldwd);
    return SUCCESS;
}

int built_cd(char **envp, char *cmd)
{
    if (case_cd(envp, cmd) == FAILURE)
        return FAILURE;
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "PWD=", 4) == 0) {
            my_strcpy(envp[i] + 4, getcwd(NULL, 0));
        }
    }
    return SUCCESS;
}
