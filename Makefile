# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:49:17 by jlaiti            #+#    #+#              #
#    Updated: 2023/01/03 18:23:21 by jlaiti           ###   ########.fr        #
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

$(NAME) : $(LIB) $(OBJS_SRCS)
	$(CC) -L. -lft -o $(NAME) $(OBJS_SRCS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_SRCS)
	${MAKE} -C libft clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
