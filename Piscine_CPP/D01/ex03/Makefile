# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:27:17 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/03 10:26:07 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon_or_not

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \


all:
	$(CXX) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
