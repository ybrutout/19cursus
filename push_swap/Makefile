# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 11:16:42 by ybrutout          #+#    #+#              #
#    Updated: 2021/07/28 15:11:24 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

SRC =	big_sorted.c \
		big_sorted_bis.c \
		both_utils.c \
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
		index.c \

SRCBONUS =	both_utils.c \
			checker.c \
			error.c \
			ft_libft.c \
			ft_libft_second.c \
			index.c \
			operation_checker.c \
			operation_checker_biss.c \
			toolbox.c \

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME)

checker: $(OBJBONUS)
	@$(CC) $(SRCBONUS) -o checker

clean:
	@rm -f $(OBJ)

chclean:
	@rm -f $(OBJBONUS)

fclean: 	clean
	@rm -f $(NAME)

fchclean: chclean
	@rm -f checker

re: fclean all

.PHONY:		all clean fclean re
