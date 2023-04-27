/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** exit
*/

#include <stdlib.h>

#include "macro.h"
#include "struct.h"
#include "utils.h"
#include "print.h"

int built_exit(env_t *env)
{
    if (print_exit() == FAILURE)
        return FAILURE;
    free_all(env);
    exit(0);
    return SUCCESS;
}
