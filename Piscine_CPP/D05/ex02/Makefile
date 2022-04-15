# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:30:59 by ybrutout          #+#    #+#              #
#    Updated: 2022/04/15 16:21:31 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= Bureaucrat_with_Form

CPP 		= c++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC 		=	main.cpp						\
				src/Bureaucrat.cpp				\
				src/AForm.cpp					\
				src/ShrubberyCreationForm.cpp	\
				src/RobotomyRequestForm.cpp		\
				src/PresidentialPardonForm.cpp	\

OBJS		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m is ready"

.cpp.o:
			@$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf *_shubbery

re:			fclean all

.PHONY:		fclean, all, re
