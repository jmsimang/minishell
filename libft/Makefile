# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/08 17:34:53 by jmsimang          #+#    #+#              #
#    Updated: 2017/09/19 16:37:04 by jmsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c ft_atoi.c ft_strlen.c ft_strcmp.c \
	ft_strncmp.c ft_strcpy.c ft_strcat.c ft_strdup.c ft_strstr.c \
	ft_strnstr.c ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlcat.c ft_strncat.c ft_strncpy.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putstr.c ft_putstr_fd.c ft_memalloc.c \
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_strjoin.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strtrim.c ft_putnbr.c ft_putnbr_fd.c ft_itoa_base.c \
	ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_strsplit.c ft_realloc.c ft_swap.c ft_wdcount.c ft_wdcopy.c \
	ft_wdlength.c ft_lstmap.c ft_lstiter.c ft_strtok.c get_next_line.c \
	ft_tokenize.c ft_strindex.c ft_strunequ.c ft_strcombine.c

OBJECTS = ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
	ft_tolower.o ft_toupper.o ft_atoi.o ft_strlen.o ft_strcmp.o \
	ft_strncmp.o ft_strcpy.o ft_strcat.o ft_strdup.o ft_strstr.o \
	ft_strnstr.o ft_strchr.o ft_strrchr.o ft_memset.o ft_bzero.o \
	ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_strlcat.o ft_strncat.o ft_strncpy.o ft_putchar.o ft_putchar_fd.o \
	ft_putendl.o ft_putendl_fd.o ft_putstr.o ft_putstr_fd.o ft_memalloc.o \
	ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_strjoin.o ft_striter.o \
	ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strtrim.o ft_putnbr.o ft_putnbr_fd.o ft_itoa_base.o \
	ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
	ft_strsplit.o ft_realloc.o ft_swap.o ft_wdcount.o ft_wdcopy.o \
	ft_wdlength.o ft_lstmap.o ft_lstiter.o ft_strtok.o get_next_line.o \
	ft_tokenize.o ft_strindex.o ft_strunequ.o ft_strcombine.o

DELFLAG = rm -f

LCFLAG = ar rc

LIFLAG = ranlib

CFLAGS = -Wall -Werror -Wextra -c

GCHFILE = ../includes/libft.h.gch

HEADER = ../includes/libft.h

all: $(NAME)

$(NAME) : $(OBJECTS)
	@echo "\t\033[0;33m------ Creating LIBFT library ------\033[0m"
	@$(LCFLAG) $(NAME) $(OBJECTS)
	@echo " "
	@echo "\t\033[0;33m------ Linking LIBFT library ------\033[0m"
	@$(LIFLAG) $(NAME)
	@echo " "

$(OBJECTS) :
	@echo " "
	@echo "\t\033[0;33m--- Compiling LIBFT source files ---\033[0m"
	@$(CC) $(CFLAGS) $(HEADER) $(SOURCES)
	@echo " "

clean:
	@echo " "
	@echo "\t\033[0;31m--> Removing LIBFT object files <--\033[0m"
	@$(DELFLAG) $(OBJECTS)
	@$(DELFLAG) $(GCHFILE)
	@echo " "

fclean:
	@echo " "
	@echo "\t\033[0;31m--> Removing LIBFT object files <--\033[0m"
	@$(DELFLAG) $(OBJECTS)
	@echo " "
	@echo "\t\033[0;31m-----> Removing LIBFT library <-----\033[0m"
	@$(DELFLAG) $(NAME)
	@$(DELFLAG) $(GCHFILE)
	@echo " "


re: fclean all
