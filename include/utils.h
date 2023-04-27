/*
** EPITECH PROJECT, 2023
** print.h
** File description:
** include for my print
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "struct.h"
    int copy_env(char *envp[], env_t *env);
    void copy_input(env_t *env, char *buf);
    void malloc_input(env_t *env);
    int check_if_path(env_t *env);
    void malloc_path(env_t *env, int nb_lines);
    void fill_path(char **env, char **path, int i);
    char *parse_env(char *env);
    void free_all(env_t *env);
    void special_free(env_t *env, char *buf);
#endif
