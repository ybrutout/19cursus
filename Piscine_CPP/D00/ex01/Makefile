# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 15:17:56 by ybrutout          #+#    #+#              #
#    Updated: 2022/03/03 10:26:07 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phone_book

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	sources/PhoneBook.cpp \
		sources/Contact.cpp \

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME):
			@$(CXX) $(CPPFLAGS) main.cpp $(SRC) -o $(NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

.cpp.o:
			@$(CXX) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		fclean, all, re
