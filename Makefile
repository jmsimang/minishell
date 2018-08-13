# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 12:42:45 by jmsimang          #+#    #+#              #
#    Updated: 2017/09/29 15:33:29 by jmsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

FLAGS = -Wall -Werror -Wextra -c

DELFLAG = rm -f

COMPILE_LIBFT = ./libft/make

LIBRARIES = -L./libft/ -lft

DELLIBFT = make -C ./libft/ fclean

SOURCES = sh_echo.c sh_setenv.c sh_environment.c sh_execute_process.c \
		  sh_cd.c sh_unsetenv.c minishell.c sh_exit.c

OBJECTS = sh_echo.o sh_setenv.o sh_environment.o sh_execute_process.o \
		  sh_cd.o sh_unsetenv.o minishell.o sh_exit.o

all : $(NAME)

$(NAME) : $(COMPILE_LIBFT) $(OBJECTS)
	@echo "\t\033[1;36m------> Compiling MINISHELL <------\033[0m"
	@$(CC) $(OBJECTS) -o $(NAME) $(LIBRARIES)
	@echo ""

$(COMPILE_LIBFT) :
	@echo ""
	@echo "\t\033[0;33m--------> Compiling LIBFT <--------\033[0m"
	@make -C ./libft/
	@echo ""

$(OBJECTS) :
	@echo "\t\033[1;36m- Compiling MINISHELL object file -\033[0m"
	@$(CC) $(FLAGS) $(SOURCES)
	@echo ""

clean :
	@make -C ./libft/ clean
	@echo "\t\033[0;31m----> Removing minishell files <----\033[0m"
	@$(DELFLAG) $(OBJECTS)
	@echo " "

fclean :
	@$(DELLIBFT)
	@echo "\t\033[0;31m----> Removing minishell file <----\033[0m"
	@echo ""
	@$(DELFLAG) $(OBJECTS)
	@$(DELFLAG) $(NAME)

re : fclean all
