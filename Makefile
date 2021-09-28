# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 11:21:59 by ybrutout          #+#    #+#              #
#    Updated: 2021/09/28 11:23:15 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	philo.c \
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@echo "I did'nt do any bonus :)"

.PHONY:		all clean fclean re
