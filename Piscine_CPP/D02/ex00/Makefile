# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 12:22:52 by ybrutout          #+#    #+#              #
#    Updated: 2022/02/23 12:23:16 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = NumberFixed

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Fixed.cpp \

all:
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
