SRCS = $(wildcard *.c ../*.c */*.c)
OBJS = ${SRCS:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -D BUFFER_SIZE=32

NAME = test.out

TESTARGS = "samples/Mili - Colorful [Original artist H△G].srt"

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

autorun: re
	./${NAME} ${TESTARGS}

all: ${NAME}

clean:
	rm -f *.o ../*.o */*.o
	rm -f *.gch ../*.gch */*.gch

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re autorun
