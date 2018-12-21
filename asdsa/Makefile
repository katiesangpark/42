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


NAME 	= 	fillit

SRC 	= 	srcs/list.c srcs/main.c srcs/reading.c srcs/solving.c srcs/validating.c srcs/printing.c

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft

all: libft/ $(NAME)

$(NAME): $(OBJ) libft Makefile
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all


.PHONY: all re clean fclean
