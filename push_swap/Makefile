# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 11:16:42 by ybrutout          #+#    #+#              #
#    Updated: 2021/07/29 11:37:31 by ybrutout         ###   ########.fr        #
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

CHECK =	checker/checker.c \
		checker/ft_libft_second.c \
		checker/operation_checker.c \
		checker/operation_checker_biss.c \

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
		source/toolbox_third.c\

SRC =	${BOTH} \
		${PS} \

SRCBONUS =	${BOTH} \
		${CHECK} \

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME) check

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME)

check: $(OBJBONUS)
	@$(CC) $(SRCBONUS) -o check

clean:
	@rm -f $(OBJ)

chclean:
	@rm -f $(OBJBONUS)

fclean: 	clean
	@rm -f $(NAME)

chfclean: chclean
	@rm -f check

afclean: chfclean fclean

re: fclean chfclean all

.PHONY:		all clean fclean re
