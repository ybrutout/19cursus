# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 13:42:59 by ybrutout          #+#    #+#              #
#    Updated: 2021/10/27 13:49:23 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

RPATH = /Users/$(USER)/.brew/opt/readline/

RL_FLAGS    =   -L/usr/include  -lreadline

SRC = essais.c\

OBJ = ${SRC:c=o}

%.o: %.c
	@${CC} ${CFLAGS} ${RFLAGS} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${RL_FLAGS} -o ${NAME} ${OBJ}

clean :
	@rm -f ${OBJ}

fclean : clean
	@rm -f ${NAME}

allup: all clean

re: clean all

