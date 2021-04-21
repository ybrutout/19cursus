# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:56:15 by mushu             #+#    #+#              #
#    Updated: 2021/04/21 16:34:40 by ybrutout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -c

FLAG = -c

SRC =	ft_check.c\
		ft_conv_flags.c \
		ft_conv_flags_p.c \
		ft_conv_flags_u.c \
		ft_conv_flags_d.c \
		ft_conv_flags_x.c \
		ft_conv_flags_X_.c \
		ft_printf.c\
		ft_tools.c \

SRCSESS = z_essais.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJBONUS)

fclean: 	clean
	@rm -f $(NAME)
	@rm -rf a.out

re: fclean all

.PHONY:		all clean fclean re
