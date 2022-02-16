# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:58:34 by yannahbruto       #+#    #+#              #
#    Updated: 2022/02/16 10:48:22 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GlobalBanksters_united

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Account.cpp \
		test.cpp\

all:
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
clean:
	@rm -f $(NAME)
