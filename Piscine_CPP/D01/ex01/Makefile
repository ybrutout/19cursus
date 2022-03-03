# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 11:59:24 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/03 10:26:07 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		ZombieHorde.cpp\
		Zombie.cpp\

all:
	$(CXX) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
