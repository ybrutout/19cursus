# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 11:02:46 by ybrutout          #+#    #+#              #
#    Updated: 2022/01/24 11:37:24 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		newZombie.cpp\
		randomChump.cpp\
		Zombie.cpp\

all:
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
