# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:50:57 by ybrutout          #+#    #+#              #
#    Updated: 2021/10/21 16:16:21 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fsanitize=address

SRC =	argument.c \
		error.c \
		libft.c \
		philo.c \
		philo_list.c \
		routine.c \
		utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@echo "I did'nt do any bonus :)"

.PHONY:		all clean fclean re
