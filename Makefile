# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuria <nuria@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:51:45 by nuria             #+#    #+#              #
#    Updated: 2023/11/27 12:43:50 by nuria            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long.a
SRC_DIR		=	./src/
C_FILES		=	so_long.c
SRC			=	$(addprefix $(SRC_DIR),$(C_FILES))
OBJS		=	$(SRC:.c=.o)
AR			=	ar rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I/mlx/
LIBFTPRINTF =	ft_printf/ft_printf.a
LIBMLX		=	mlx/mlx.a
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBMLX)
	$(AR) $(NAME) $(OBJS) $(LIBFTPRINTF) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

$(LIBFTPRINTF):
	make -C ft_printf

$(LIBMLX):
	make -C mlx

clean:
	rm -f $(OBJS)
	make -C ft_printf clean
	make -C mlx clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTPRINTF)
	rm -f $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re