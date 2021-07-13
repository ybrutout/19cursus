# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 11:47:40 by ybrutout          #+#    #+#              #
#    Updated: 2021/07/13 11:47:52 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address -c

SRC =	push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -fsanitize=address -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:		all clean fclean re
