/*
** EPITECH PROJECT, 2023
** Ini_struct
** File description:
** EPITECH Project main
*/

#include <stddef.h>

#include "mysh.h"
#include "macro.h"


static int error(int ac, char *av[], char *envp[])
{
    if (ac != 1
    || av == NULL
    || envp == NULL)
        return FAILURE;

    return SUCCESS;
}

int main(int argc, char *argv[], char *envp[])
{
    if (error(argc, argv, envp) == FAILURE
    || minishell_init(envp) == FAILURE)
        return FAILURE;

    return SUCCESS;
}
