NAME2 = client

NAME = server

CC = gcc

FLAGS = -Wall -Wextra -Werror

CLIENT =	src_client/client.c \

SERVER =	src_server/server.c \
			src_server/server_utils.c \

BOTH =		both/utils.c \
			both/second_utils.c \

CLIENT_BONUS =	bonus/client_bonus.c \
				bonus/client_utils_bonus.c \

SERVER_BONUS = 	bonus/server_bonus.c \
				bonus/server_utils_bonus.c \

SRC2 = $(CLIENT)

SRC = $(SERVER)

SRC_BONUS =	$(CLIENT_BONUS) $(SERVER_BONUS)

OBJ2 = ${SRC2:.c=.o}

OBJ = ${SRC:.c=.o}

OBJBOTH = ${BOTH:.c=.o}

OBJBONUS = ${SRC_BONUS:.c=.o}

all: $(NAME) $(NAME2)

$(NAME): $(OBJ) $(OBJBOTH)
	@$(CC) $(FLAGS) $(SRC) $(BOTH) -o $(NAME)

$(NAME2): $(OBJ2) $(OBJBOTH)
	@$(CC) $(FLAGS) $(SRC2) $(BOTH) -o $(NAME2)

both: $(NAME) $(NAME2)

bonus: $(OBJBONUS) $(OBJBOTH)
	@$(CC) $(FLAGS) $(SERVER_BONUS) $(BOTH) -o $(NAME)
	@$(CC) $(FLAGS) $(CLIENT_BONUS) $(BOTH) -o $(NAME2)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	@rm -f $(OBJBOTH)
	@rm -f $(OBJBONUS)

fclean: 	clean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all

.PHONY:		all clean fclean re
