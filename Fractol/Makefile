# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:34:10 by ybrutout          #+#    #+#              #
#    Updated: 2021/08/16 15:35:17 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

SRC =	fractol.c \

SRCLIB = libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGMLX) $(SRC) $(SRCLIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
