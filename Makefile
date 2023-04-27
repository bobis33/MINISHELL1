##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## EPITECH Project
##

SRC_MAIN 		=	src/main.c

SRC_LIB			=	src/lib/my_putstr.c 					\
					src/lib/my_strlen.c 					\
					src/lib/my_strcpy.c 					\
					src/lib/my_strncmp.c 					\
					src/lib/my_strcmp.c 					\
					src/lib/my_alphanum.c 					\
					src/lib/my_array_len.c 					\
					src/lib/my_strcat.c

SRC_UTILS		= 	src/utils/parse_env.c 					\
					src/utils/is_path.c 					\
					src/utils/copy/env.c 					\
					src/utils/copy/input.c 					\
					src/utils/memory/my_malloc.c 			\
					src/utils/memory/free_all.c

SRC_PRINTS		=	src/prints/print_prompt.c				\
					src/prints/print_error.c				\
					src/prints/print_cmd.c

SRC				=	src/minishell/minishell.c				\
					src/minishell/handler.c					\
					src/minishell/child_process.c			\
					src/minishell/builtins/builtins.c		\
					src/minishell/builtins/cd.c				\
					src/minishell/builtins/exit.c			\
					src/minishell/builtins/setenv.c			\
					src/minishell/builtins/unsetenv.c

SRC_TEST		=	units_tests/test.c

OBJ 			=	$(SRC_MAIN:.c=.o)						\
					$(SRC_LIB:.c=.o)						\
					$(SRC_UTILS:.c=.o)						\
					$(SRC_PRINTS:.c=.o)						\
					$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_LIB:.c=.o) 						\
					$(SRC_UTILS:.c=.o)						\
					$(SRC:.c=.o)							\
					$(SRC_PRINTS:.c=.o)						\
					$(SRC_TEST:.c=.o)

CFLAGS			=	-W -Wall -Wextra -I./include

FLAGS_DEBUG 	= 	-g3

FLAGS_TEST 		=	--coverage -lcriterion

NAME			=	mysh

NAME_TEST		= 	unit_tests

$(NAME):			$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:				$(NAME)

debug: 				CFLAGS += $(FLAGS_DEBUG)

debug:				$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
					rm -rf $(OBJ)
					rm -rf $(NAME)

clean_test:
					rm -rf $(OBJ_TEST)
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:				clean clean_test
					rm -rf $(NAME_TEST)

tests_run:			CFLAGS += --coverage

tests_run: 			$(OBJ_TEST)
					gcc -o $(NAME_TEST) $(OBJ_TEST) $(CFLAGS) $(FLAGS_TEST)
					./unit_tests --verbose

re:					fclean all

.PHONY: 			all debug clean clean_test fclean tests_run re
