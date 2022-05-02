# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 19:16:06 by rrangwan          #+#    #+#              #
#    Updated: 2022/01/28 13:09:46 by rrangwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c ft_printer.c

CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
