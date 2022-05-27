# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 15:32:18 by bgrulois          #+#    #+#              #
#    Updated: 2022/05/10 19:18:32 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

NAME_B	=	pipex_bonus

SRCS	=	ft_strlen.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_strdup.c \
		get_next_line_utils.c \
		get_next_line.c \
		pipex_utils.c \
		pipex_structs_init.c \
		pipex.c \
		main.c

SRCS_B	=	ft_strlen.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_strdup.c \
		get_next_line_utils.c \
		get_next_line.c \
		pipex_utils.c \
		pipex_structs_init.c \
		pipex.c \
		main_bonus.c

CC	=	gcc	

CFLAGS	=	-Wall -Wextra -Werror -g3

OBJS	=	${SRCS:%.c=%.o}

OBJS_B	=	${SRCS_B:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

bonus:		${NAME_B}

${NAME_B}:	${OBJS_B}
		${CC} ${CFLAGS} -o ${NAME_B} ${OBJS_B}

clean:		
		rm -rf ${OBJS} ${OBJS_B}

fclean:		clean
		rm -rf ${NAME} ${NAME_B}

re:		fclean all

.PHONY:		all clean fclean re bonus
