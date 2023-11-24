# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 16:58:12 by nuria             #+#    #+#              #
#    Updated: 2023/11/21 18:26:00 by nurreta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= so_long.c \

OBJS	= $(SRCS:.c=.o)

AR		= ar rc

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -I./mlx/ -L./mlx/# -g3 -fsanitize=address

NAME	= so_long.a

all:	lib $(NAME)

$(NAME):	$(SRC) $(OBJS) so_long.h 
		$(CC) $(FLAGS) -lnlx -framework OpenGl -framework AppKit $(SRC) -o $(NAME)

%.o: %.CC
		$(CC) -c $(FLAGS) -Imlx $< -o $@

execute:
		./$(NAME) maps/map1.ber

clean:
		$(RM) $(OBJS) 
		$(MAKE) -C minilibx_opengl clean

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

lib:
	$(NAME) -C minilibx_opengl re

.PHONY:		all clean fclean re