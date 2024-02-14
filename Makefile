# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 07:12:28 by nuria             #+#    #+#              #
#    Updated: 2024/01/03 16:28:39 by nurreta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

SRC     = main.c error.c check_map.c path_checker.c draw_map.c input.c  \
		  utils.c libft_utils.c get_next_line.c

OBJS    = $(SRC:.c=.o)

AR      = ar rc

LIB     = ranlib

CC      = gcc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror -I./mlx/ #-g3 -fsanitize=address -fsanitize=undefined

all: lib $(NAME)

$(NAME): $(OBJS) so_long.h
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C mlx clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

lib:
	$(MAKE) -C mlx

.PHONY: all clean fclean re lib