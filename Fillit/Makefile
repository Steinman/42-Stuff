# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 14:36:28 by hcorrale          #+#    #+#              #
#    Updated: 2016/01/08 17:10:32 by hcorrale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

HEADER		= includes/fillit.h

FLAGS		= -Wall -Wextra -Werror

SRCS_PATH	= srcs

SRCS		= main.c \
			  error.c \
			  misc.c

OBJ			= $(SRCS:.c=.o)

$(NAME):
			@gcc $(FLAGS) -c $(SRCS_PATH)/$(SRCS) -I $(HEADER)
			@ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
			@rm -f $(SRCS_PATH)/$(OBJ)

fclean: clean
			@rm -f $(NAME)

re: fclean all
