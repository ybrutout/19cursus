# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 11:16:42 by ybrutout          #+#    #+#              #
#    Updated: 2021/08/02 10:51:36 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

BOTH =	both/both_utils.c \
		both/error.c \
		both/ft_libft.c \
		both/index.c \
		both/toolbox.c \
		both/toolbox_third.c\

CHECK =	check/checker.c \
		check/ft_libft_second.c \
		check/operation_checker.c \
		check/operation_checker_biss.c \

PS =	source/big_sorted.c \
		source/big_sorted_bis.c \
		source/little_sorted.c \
		source/middlepoint.c \
		source/operation_biss.c \
		source/operation.c \
		source/position.c \
		source/push_swap.c \
		source/sorted.c \
		source/toolbox_second.c \

SRC =	${BOTH} \
		${PS} \

SRCBONUS =	${BOTH} \
		${CHECK} \

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

chfclean: chclean
	@rm -f checker

afclean: chfclean fclean

re: fclean chfclean all

.PHONY:		all clean fclean re
