# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:21:55 by bgrulois          #+#    #+#              #
#    Updated: 2021/12/22 18:18:53 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS =		./utils/

SRCS = 		${UTILS}ft_putchar_fd.c\
       		${UTILS}ft_putnbr_fd.c\
		${UTILS}ft_putunbr_fd.c\
       		${UTILS}ft_putstr_fd.c\
		${UTILS}ft_putaddr_fd.c\
		${UTILS}ft_putnbr_hex_fd.c\
       		${UTILS}ft_strlen.c\
		${UTILS}ft_printf.c

OBJS =		${SRCS:.c=.o}

NAME =		libftprintf.a

CFLAGS =	-Wall -Werror -Wextra

all :		${NAME}

$(NAME):	${OBJS}
		ar -rc ${NAME} ${OBJS}

.c.o:
		cc ${CFLAGS} -I./libft/ -c $^ -o $@

clean:
		rm -rf ${OBJS}

fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
