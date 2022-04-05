# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:30:59 by ybrutout          #+#    #+#              #
#    Updated: 2022/04/04 15:33:35 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= Brain

CXX 		= c++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC 		=	main.cpp		\
				src/Animal.cpp	\
				src/Dog.cpp		\
				src/Cat.cpp		\
				src/Brain.cpp	\

OBJS		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
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
