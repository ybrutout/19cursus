# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 15:34:10 by ybrutout          #+#    #+#              #
#    Updated: 2021/09/22 11:56:18 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

SRC =	src/error.c \
		fractol.c \
		src/init.c \
		src/fractal/julia.c \
		src/libft.c \
		src/fractal/mandelbrot.c \
		src/move.c \

SRCLIB = libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGMLX) $(CFLAGS) $(OBJ) $(SRCLIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@echo "I did'nt do any bonus :)"

.PHONY:		all clean fclean re
