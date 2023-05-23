# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 00:48:13 by slegaris          #+#    #+#              #
#    Updated: 2023/05/23 03:06:24 by slegaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_countnbr.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_unsg.c \
		ft_putnbrhex_mayus.c \
		ft_putnbrhex_minus.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_strlen.c \

OBJS =	$(SRCS:.c=.o)

CC =	gcc

RM =	rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
