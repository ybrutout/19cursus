NAME = client

NAME2 = server

CC = gcc

FLAGS = -Wall -Wextra -Werror

CLIENT =	client.c \
			libft.c \

SERVER =	server.c \

SRC = $(CLIENT)

SRC2 = $(SERVER)

OBJ = $(SRCCLIENT:.c=.o)

OBJ2 = $(SRCSERVER:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME2): $(OBJ2)
	@$(CC) $(FLAGS) $(SRC2) -o $(NAME2)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all

.PHONY:		all clean fclean re
