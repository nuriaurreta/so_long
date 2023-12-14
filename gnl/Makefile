# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuria <nuria@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 11:00:21 by nuria             #+#    #+#              #
#    Updated: 2023/12/05 16:09:13 by nuria            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

SRCS	= get_next_line.c get_next_line_utils.c #leaks.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -DBUFFER_SIZE=42

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:		all clean fclean re