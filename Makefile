# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuria <nuria@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2023/11/29 07:12:28 by nuria             #+#    #+#              #
#    Updated: 2023/12/13 17:34:43 by nurreta          ###   ########.fr        #
=======
#    Created: 2023/11/23 16:51:45 by nuria             #+#    #+#              #
#    Updated: 2023/11/27 12:43:50 by nuria            ###   ########.fr        #
>>>>>>> be577f12cdf0de29a7de04a7868de549686467c1
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

<<<<<<< HEAD
SRC		=	so_long.c libft_utils.c error.c map.c get_next_line.c load_xpm.c  \
			draw_map.c status.c utils.c
			

OBJS	= $(SRC:.c=.o)
=======
all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(LIBMLX)
	$(AR) $(NAME) $(OBJS) $(LIBFTPRINTF) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)
>>>>>>> be577f12cdf0de29a7de04a7868de549686467c1

$(LIBFTPRINTF):
	make -C ft_printf

<<<<<<< HEAD
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
=======
$(LIBMLX):
	make -C mlx

clean:
	rm -f $(OBJS)
	make -C ft_printf clean
	make -C mlx clean
>>>>>>> be577f12cdf0de29a7de04a7868de549686467c1

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTPRINTF)
	rm -f $(LIBMLX)

<<<<<<< HEAD
lib:
	$(MAKE) -C mlx

.PHONY:		all execute clean fclean re lib
=======
re: fclean all

.PHONY: all clean fclean re
>>>>>>> be577f12cdf0de29a7de04a7868de549686467c1
