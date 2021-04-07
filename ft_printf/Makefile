# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:56:15 by mushu             #+#    #+#              #
#    Updated: 2021/04/07 12:26:16 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -c

SRC =	ft_conv_type.c \
		tools.c \
		main.c \
		ft_check.c \
		ft_printf.c \
		ft_conv_flags.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJBONUS)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

a: re
	@$(CC) -o a.out $(OBJ)
	@./a.out

.PHONY:		all clean fclean re
