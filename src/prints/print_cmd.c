/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** print_cmd
*/

#include <unistd.h>
#include <sys/stat.h>

#include "lib.h"
#include "struct.h"
#include "macro.h"


int print_cd(char *path)
{
    struct stat sb;
    if (stat(path, &sb) == -1) {
        if (my_put_strerr(path) == FAILURE
        || my_put_strerr(": No such file or directory.\n") == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    if (!S_ISDIR(sb.st_mode)) {
        if (my_put_strerr(path) == FAILURE
        || my_put_strerr(": Not a directory.\n") == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    if (access(path, R_OK) == -1) {
        if (my_put_strerr(path) == FAILURE
        || my_put_strerr(": Permission denied.\n") == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    return SUCCESS;
}

int print_env(char **envp)
{
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_put_str(envp[i]) == FAILURE
        || my_put_str("\n") == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int print_exit(void)
{
    if (my_put_str("exit\n") == FAILURE)
        return FAILURE;
    return SUCCESS;
}
