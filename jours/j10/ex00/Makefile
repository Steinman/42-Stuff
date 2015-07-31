# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 17:16:51 by hcorrale          #+#    #+#              #
#    Updated: 2015/07/21 19:23:57 by hcorrale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_strlen.c \
	   srcs/ft_swap.c

OBJS = ft_putchar.o \
	   ft_putstr.o \
	   ft_strcmp.o \
	   ft_strlen.o \
	   ft_swap.o

GFLAG = -Wall -Wextra -Werror -c

LIB = includes

all: $(NAME)

$(NAME):
	gcc $(GFLAG) -I $(LIB) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
