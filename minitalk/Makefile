NAME2 = client

NAME = server

CC = gcc

FLAGS = -Wall -Wextra -Werror

CLIENT =	client.c \

SERVER =	server.c \
			server_utils.c \

BOTH =		utils.c \
			second_utils.c \

SRC2 = $(CLIENT)

SRC = $(SERVER)

OBJ2 = $(SRCCLIENT:%.c=%.o)

OBJ = $(SRCSERVER:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(BOTH) -o $(NAME)

$(NAME2): $(OBJ2)
	$(CC) $(SRC2) $(BOTH) -o $(NAME2)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: 	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY:		all clean fclean re
