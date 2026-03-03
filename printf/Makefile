# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 08:58:06 by rstrcic           #+#    #+#              #
#    Updated: 2025/12/10 11:15:59 by qbourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
SRC =   hex_function.c \
		main_printf.c \
		search_param.c \
		write_function.c \
		ptr_function.c \
		itoa.c \
		function_2exit.c \
		function_2exit2.c

ICL = ft_printf.h 
OBJ = ${SRC:.c=.o}
CFLAGS += -Wall -Wextra -Werror
CUR_DIR = ${shell pwd}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${ICL} -c $< -o $@

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re