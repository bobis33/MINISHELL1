/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell2-elliot.masina
** File description:
** my_alphanum
*/


int my_alphanum(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9') &&
            str[i] != '_' && str[i] != '.')
            return 1;
    }
    return 0;
}
