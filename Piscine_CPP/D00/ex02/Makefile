# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:58:34 by yannahbruto       #+#    #+#              #
#    Updated: 2022/02/16 14:32:55 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GlobalBanksters_united

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	src/Account.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME):
			@$(CC) $(CPPFLAGS) test.cpp $(SRC) -o $(NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

.cpp.o:
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		fclean, all, re
