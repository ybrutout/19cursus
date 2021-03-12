# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mushu <mushu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:56:15 by mushu             #+#    #+#              #
#    Updated: 2021/03/09 12:00:19 by mushu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -c

SRC = 	ft_printf.c \
		conversions_type.c \
		free.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus