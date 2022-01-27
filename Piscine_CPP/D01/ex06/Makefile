# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 14:21:27 by ybrutout          #+#    #+#              #
#    Updated: 2022/01/26 14:22:19 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = karenFilter

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Karen.cpp \

all:
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
