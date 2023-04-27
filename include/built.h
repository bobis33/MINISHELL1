/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-elliot.masina
** File description:
** built
*/

#ifndef BUILT_H_
    #define BUILT_H_
    #include "struct.h"
    int built_cd(char **envp, char *cmd);
    int built_exit(env_t *env);
    int built_setenv(char **envp, char **cmd);
    int built_unsetenv(char **envp, char *cmd);
#endif /* !BUILT_H_ */
