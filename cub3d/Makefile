# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 13:51:32 by ybrutout          #+#    #+#              #
#    Updated: 2021/05/06 12:46:57 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

SRC =	check_file.c \
		draw_mini_map.c \
		cub3d.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

SRCLIB = libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGMLX) $(SRC) $(SRCLIB) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:		all clean fclean re
