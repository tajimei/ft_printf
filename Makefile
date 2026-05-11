# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meitajima <mtajima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 15:32:34 by mtajima         #+#    #+#              #
#    Updated: 2026/05/11 15:32:35 by mtajima        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 