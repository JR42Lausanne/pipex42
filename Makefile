# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:49:17 by jlaiti            #+#    #+#              #
#    Updated: 2023/01/04 15:55:33 by jlaiti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  	pipex.c			\
		pipex_init_fd.c		\
		execute_process.c	\
		init_process.c		\


NAME = pipex
LIB  = libft.a

OBJS_SRCS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(LIB):
	cd libft/ && make && cp -v libft.a ../ 

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(LIB) $(OBJS_SRCS)
	$(CC) -L. -lft -o $(NAME) $(OBJS_SRCS)

clean:
	rm -rf $(OBJS_SRCS)
	${MAKE} clean -C libft

fclean: clean
	rm -rf $(NAME) $(LIB)
	${MAKE} fclean -C libft

re: fclean all

.PHONY : all clean fclean re

DEFAULT = \033[0m
GREEN = \033[1;32m
