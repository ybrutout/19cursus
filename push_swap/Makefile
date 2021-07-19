# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 11:16:42 by ybrutout          #+#    #+#              #
#    Updated: 2021/07/19 09:06:50 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

SRC =	big_sorted.c \
		big_sorted_bis.c \
		error.c \
		ft_libft.c \
		little_sorted.c \
		middlepoint.c \
		operation.c \
		operation_biss.c \
		position.c \
		push_swap.c \
		sorted.c \
		toolbox.c \
		toolbox_2.c \
		toolbox_3.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:		all clean fclean re
