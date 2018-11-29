#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 07:10:44 by kicausse          #+#    #+#              #
#    Updated: 2018/11/26 05:28:20 by kicausse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= 	libftprintf

SRC 	= 	srcs/ft_printf.c srcs/lists.c srcs/options.c

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft

all: $(NAME)

$(NAME): $(OBJ) Makefile 
	ar rc $(NAME).a $(OBJ) 

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all


.PHONY: all re clean fclean
