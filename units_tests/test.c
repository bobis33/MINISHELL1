/*
** EPITECH PROJECT, 2023
** Ini_struct
** File description:
** test
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test(test1, error_return_value) {
    int argc = 0;
    char **argv = NULL;
    char **envp = NULL;
    cr_assert(error(argc, argv, envp) == 84);
}

Test(test2, error_str_output_argv, .init = cr_redirect_stderr) {
    int argc = 0;
    char **argv = NULL;
    char **envp = NULL;
    error(argc, argv, envp);
    cr_assert_stderr_eq_str("Error Bad arguments.\n");
}

Test(test3, leave_minishell, .init = cr_redirect_stdout) {
    print_leave_minishell();
    cr_assert_stdout_eq_str("\nYou left Minishell . . .\n");
}

Test(test4, error_str_output_envp, .init = cr_redirect_stderr) {
    int argc = 1;
    char *argv[0];
    argv[0] = "cc";
    char **envp = NULL;
    error(argc, argv, envp);
    cr_assert_stderr_eq_str("Error cannot find environment.\n");
}
