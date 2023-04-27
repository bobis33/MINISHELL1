/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    int my_put_str(char const *str);
    int my_put_strerr(char const *str);
    int my_strlen(char const *str);
    char const *my_strcpy(char *dest, char const * src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcat(char *dest, char *src);
    int my_alphanum(char const *str);
    int my_array_len(char **array);
#endif /* !LIB_H_ */
