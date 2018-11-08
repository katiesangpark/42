# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 16:05:02 by gguichar          #+#    #+#              #
#    Updated: 2018/07/24 16:06:34 by fwerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/utils.c \
	   srcs/ft_functions.c \
	   srcs/read_map.c \
	   srcs/read_utils.c \
	   srcs/print_map.c \
	   srcs/main.c

HEADERS = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I $(HEADERS) -o $(NAME) $(SRCS)

clean:

fclean:
	/bin/rm -f $(NAME)

re: fclean all
