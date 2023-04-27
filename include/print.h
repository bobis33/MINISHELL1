/*
** EPITECH PROJECT, 2023
** print.h
** File description:
** include for my prints
*/

#ifndef PRINT_H_
    #define PRINT_H_
    #include "struct.h"
    int print_prompt(env_t *env);
    int print_error(char **cmd);
    int print_segfault(int status);
    int print_env(char **envp);
    int print_exit(void);
    int print_cd(char *path);
#endif
