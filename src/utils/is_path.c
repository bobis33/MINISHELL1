/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-elliot.masina
** File description:
** is_path
*/

#include "macro.h"
#include "struct.h"

int check_if_path(env_t *env)
{
    for (int i = 0; env->cmd[0][i] != '\0'; i++) {
        if (env->cmd[0][i] == '/')
            return 1;
    }
    return SUCCESS;
}
