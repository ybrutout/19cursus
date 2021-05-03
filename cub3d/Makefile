# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 13:51:32 by ybrutout          #+#    #+#              #
#    Updated: 2021/05/03 12:31:13 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

SRC = essais.c\

SRCLIB = libmlx.a

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(FLAGMLX) $(SRC) $(SRCLIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

a: re
	@$(CC) -o a.out $(OBJ) $(SRCLIB)
	@./a.out

.PHONY:		all clean fclean re
