# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:13:41 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/30 08:58:08 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PointFixed

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	src/bsp.cpp			\
		src/Fixed.cpp	\
		src/Point.cpp	\
		main.cpp		\

OBJS		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):
			@$(CXX) $(CPPFLAGS) $(SRC) -o $(NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

.cpp.o:
			@$(CXX) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		fclean, all, re
