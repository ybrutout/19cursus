NAME2 = client

NAME = server

CC = gcc

FLAGS = -Wall -Wextra -Werror

CLIENT =	src_client/client.c \

SERVER =	src_server/server.c \
			src_server/server_utils.c \

BOTH =		both/utils.c \
			both/second_utils.c \

SRC2 = $(CLIENT)

SRC = $(SERVER)

OBJ2 = ${SRC2:.c=.o}

OBJ = ${SRC:.c=.o}

OBJBOTH = ${BOTH:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(OBJBOTH)
	$(CC) $(FLAGS) $(SRC) $(BOTH) -o $(NAME)

$(NAME2): $(OBJ2) $(OBJBOTH)
	$(CC) $(FLAGS) $(SRC2) $(BOTH) -o $(NAME2)

both: $(NAME) $(NAME2)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)
	rm -f $(OBJBOTH)

fclean: 	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY:		all clean fclean re
