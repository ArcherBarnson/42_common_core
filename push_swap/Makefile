# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 15:32:18 by bgrulois          #+#    #+#              #
#    Updated: 2022/05/27 17:08:43 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	ft_bzero.c \
		ft_atoi.c \
		ft_atoll.c \
		ft_parsing.c \
		instructions.c \
		instructions_2.c \
		std_algos.c \
		ft_radix.c \
		main.c

CC	=	gcc	

CFLAGS	=	-Wall -Wextra -Werror -g3

OBJS	=	${SRCS:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
		rm -rf ${OBJS}

fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
