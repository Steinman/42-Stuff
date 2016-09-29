# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 16:54:52 by hcorrale          #+#    #+#              #
#    Updated: 2016/04/13 16:52:56 by hcorrale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SRC = ft_isascii.c \
	  ft_isprint.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoi.c \
	  ft_atoi_nb.c \
	  ft_bzero.c \
	  ft_memccpy.c \
	  ft_memcpy.c \
	  ft_memchr.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_memcmp.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strdup.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strlen.c \
	  ft_strlcat.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strnew.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_abs.c \
	  ft_swap.c \
	  ft_isdigitchar.c \
	  ft_power.c \
	  ft_sqrt.c \
	  get_next_line.c \

OBJ = $(SRC:.c=.o)

$(NAME):
					@gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADERS)
					@ar rc $(NAME) $(OBJ)
					@ranlib $(NAME)

all: $(NAME)

clean:
					@rm -f $(OBJ)

fclean: clean
					@rm -f $(NAME)

re: fclean all
