# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/26 21:24:43 by hcorrale          #+#    #+#              #
#    Updated: 2015/07/26 22:36:56 by abrisse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRC =	srcs/main.c \
		srcs/ft_colles.c srcs/ft_put.c srcs/ft_str.c \
		srcs/colle00.c srcs/colle01.c srcs/colle02.c \
		srcs/colle03.c srcs/colle04.c
HEADERS = includes/
OBJ =	main.o \
		ft_colles.o	ft_put.o ft_str.o \
		colle00.o colle01.o colle02.o colle03.o colle04.o
COMPILER = gcc
OPTION1 = -c
OPTION2 = -I
OPTION3 = -o
FLAGS = -Wall -Wextra -Werror
CLEAN = /bin/rm -f

all: $(NAME)

$(NAME):
	$(COMPILER) $(OPTION1) $(FLAGS) $(SRC) $(OPTION2) $(HEADERS)
	$(COMPILER) $(OBJ) $(OPTION3) $(NAME)

clean:
	$(CLEAN) $(OBJ)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all
