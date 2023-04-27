/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct env{
        int passed;
        char *tmp;
        char **cmd;
        char **path;
        char **env;
    }env_t;
#endif
