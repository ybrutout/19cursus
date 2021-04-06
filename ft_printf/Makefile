# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:56:15 by mushu             #+#    #+#              #
#    Updated: 2021/04/06 12:30:45 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -c

SRC = 	ft_printf.c \
		ft_conv_type.c \
		free.c \
		main.c \
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

.PHONY:		all clean fclean re bonus
