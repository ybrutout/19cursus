NAME 		=	FT_TESTER

STD_NAME	=	STD_TESTER	

CPP 		=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC 		=	main_ft.cpp	\
				src/stack.cpp	\
				src/map.cpp		\
				src/vector.cpp	\

SRC_STD		=	main_std.cpp	\
				src/stack_std.cpp	\
				src/map_std.cpp		\
				src/vector_std.cpp	\

OBJS		=	$(SRC:%.cpp=%.o)

OBJS_STD	=	$(SRC_STD:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJS) $(OBJS_STD)
			$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)
			$(CPP) $(CPPFLAGS) $(SRC_STD) -o $(STD_NAME)
			@echo "The executable \033[38;2;39;154;186m$(NAME)\033[0m and \033[38;2;39;154;186m$(STD_NAME)\033[0m is ready"

std:		$(OBJS_STD)
			$(CPP) $(CPPFLAGS) $(SRC_STD) -o STD_tester

ft:			$(OBJS)
			$(CPP) $(CPPFLAGS) $(SRC) -o FT_tester

.cpp.o:
			$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

clean:
			@rm -rf $(OBJS)
			@rm -rf $(OBJS_STD)

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf $(STD_NAME)

re:			fclean all

.PHONY:		fclean, all, re