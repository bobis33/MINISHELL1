/*
** EPITECH PROJECT, 2023
** mysh.h
** File description:
** EPITECH Project Include necessary
*/

#ifndef MY_SH_
    #define MY_SH_
    #include "struct.h"
    int minishell_init(char *envp[]);
    void handle_path(env_t *env);
    int handle_line(env_t *env);
    int builtins(env_t *env);
    int child_process(env_t *env);
#endif
