# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 11:46:59 by rstrcic           #+#    #+#              #
#    Updated: 2025/12/17 11:45:23 by qbourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
SRCLIB = push_swap.c disorder.c bench.c identify_flag.c make_stack.c selection_sort.c \
		rotate_function.c swap.c push.c reverse_function.c block_sort.c for_three.c\
		find.c utils_pushswap.c radix_sort.c error.c radix_utils.c free_array.c
OBJ = ${SRCLIB:.c=.o}
CFLAGS = -Wall -Wextra -Werror -I includes

all: ${NAME}

${NAME}: ${OBJ}
	@${MAKE} -C ./libft
	@${MAKE} -C ./printf
	@${CC} ${CFLAGS} ${OBJ} ./libft/libft.a ./printf/libftprintf.a -o ${NAME}

clean:
	make clean -C ./printf
	make clean -C ./libft
	rm -f ${OBJ}

fclean: clean
	make fclean -C ./printf
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
