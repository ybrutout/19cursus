# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:34:10 by ybrutout          #+#    #+#              #
#    Updated: 2021/09/20 12:57:49 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

FLAGMLX = -fsanitize=address -g -lmlx -framework OpenGL -framework AppKit

SRC =	error.c \
		fractol.c \
		frame.c \
		julia.c \
		libft.c \
		mandelbrot.c \
		move.c \
		utils.c \



SRCLIB = libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGMLX) $(OBJ) $(SRCLIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
