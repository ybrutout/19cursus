# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 11:16:58 by ybrutout          #+#    #+#              #
#    Updated: 2021/10/19 15:30:29 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = ##-Wall -Wextra -Werror ##-fsanitize=address

SRC =	argument.c \
		error.c \
		get_the_time.c \
		libft.c \
		philo.c \
		philo_list.c \
		routine.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@echo "I did'nt do any bonus :)"

.PHONY:		all clean fclean re
