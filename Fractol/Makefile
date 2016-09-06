# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 16:54:52 by hcorrale          #+#    #+#              #
#    Updated: 2016/09/06 14:27:37 by hcorrale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fractol.h

SRC =	main.c \
		draw.c \
		math.c \
		init.c \

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
