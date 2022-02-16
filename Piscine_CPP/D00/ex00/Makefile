# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 13:33:52 by ybrutout          #+#    #+#              #
#    Updated: 2022/02/16 14:23:33 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	megaphone.cpp

all: $(NAME)

$(NAME):
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean, all, re

