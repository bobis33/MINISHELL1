/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** print_error
*/


#include <errno.h>
#include <sys/wait.h>

#include "macro.h"
#include "lib.h"


int print_segfault(int status)
{
    if (status == 136) {
        if (my_put_strerr("Floating exception") == FAILURE)
            return FAILURE;
    } else {
        if (my_put_strerr("Segmentation fault") == FAILURE)
            return FAILURE;
    }
    if (WCOREDUMP(status)
    && my_put_strerr(" (core dumped)") == FAILURE)
        return FAILURE;
    if (my_put_strerr("\n") == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int print_error(char **cmd)
{
    if (errno == 13) {
        if (my_put_strerr(cmd[0]) == FAILURE
        || my_put_strerr(": Permission denied.\n") == FAILURE)
            return FAILURE;
    } if (errno == 8) {
        if (my_put_strerr(cmd[0]) == FAILURE
        || my_put_strerr(
        ": Exec format error. Wrong Architecture.\n") == FAILURE)
            return FAILURE;
    } if (errno == 2) {
        if (my_put_strerr(cmd[0]) == FAILURE
        || my_put_strerr(": Command not found.\n") == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
