#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 21:16:44 by kicausse          #+#    #+#              #
#    Updated: 2018/07/07 21:16:45 by kicausse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft

SRC = srcs/ft_putchar.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strcmp.c \
	  srcs/ft_strlen.c \
	  srcs/ft_swap.c \

OBJECTS = ft_putchar.o \
		  ft_putstr.o \
		  ft_strcmp.o \
		  ft_strlen.o \
		  ft_swap.o \

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -Iincludes -c $(SRC)
		ar rc libft.a $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f libft.a

re: fclean all