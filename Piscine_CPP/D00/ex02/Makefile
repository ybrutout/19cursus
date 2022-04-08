# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:58:34 by yannahbruto       #+#    #+#              #
#    Updated: 2022/04/08 10:46:45 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GlobalBanksters_united

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	src/ACPPount.cpp

OBJS		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) test.cpp $(SRC) -o $(NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

.cpp.o:
			@$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		fclean, all, re
