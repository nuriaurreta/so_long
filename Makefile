# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 07:12:28 by nuria             #+#    #+#              #
#    Updated: 2023/12/13 17:34:43 by nurreta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		=	so_long.c libft_utils.c error.c map.c get_next_line.c load_xpm.c  \
			draw_map.c status.c utils.c
			

OBJS	= $(SRC:.c=.o)

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -I./mlx/ #-L./mlx/

all:	lib $(NAME)

$(NAME): $(SRC) $(OBJS) so_long.h
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.CC
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

execute:
	./$(NAME) maps/map1ok.ber

clean:
	$(RM) $(OBJS)
#	$(MAKE) -C mlx clean

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

lib:
	$(MAKE) -C mlx

.PHONY:		all execute clean fclean re lib