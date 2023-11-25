# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuria <nuria@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:51:45 by nuria             #+#    #+#              #
#    Updated: 2023/11/25 17:41:22 by nuria            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRC = src/, so_long.c

PRINTF_SRC = ft_printf/, ft_printf.c ft_strlen.c ft_printchar.c ft_print_str.c \
	ft_print_pointer.c ft_print_integer.c ft_print_integer_unsig.c

OBJS := $(SRC:%.c=%.o)

PRINTF_OBJS := $(PRINTF_SRC:%.c=%.o)

AR	= ar rc

CC = gcc

CFLAGS = -Wextra -Wall -Werror -I/mlx/ -L./mlx/# -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS) so_long.h
	gcc $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

execute:
	./$(NAME) maps/map1.ber

clean:
	rm -f $(OBJS) $(PRINTF_OBJS)
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)

re:	fclean all

lib:
	$(NAME) -C mlx re

.PHONY:	all execute clean fclean re lib