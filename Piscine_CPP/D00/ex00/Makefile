# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 13:33:52 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/03 10:26:07 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	megaphone.cpp

all: $(NAME)

$(NAME):
	@$(CXX) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

fclean:
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean, all, re

