# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yannahbrutout <yannahbrutout@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:18:50 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/24 15:25:40 by yannahbruto      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= FragTrap

CXX 		= c++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC 		=	main.cpp \
				src/ClapTrap.cpp \
				src/ScavTrap.cpp \
				src/FragTrap.cpp \

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
