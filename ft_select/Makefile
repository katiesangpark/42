# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 23:49:44 by kicausse          #+#    #+#              #
#    Updated: 2019/01/20 23:52:18 by kicausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	ft_select

SRC 	= 	srcs/main.c srcs/utils.c srcs/list.c srcs/terminal.c srcs/input.c \
			srcs/signals.c

INC 	= 	includes/structs.h includes/list.h includes/utils.h

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft -Iincludes -fsanitize=address

all: $(NAME) libft/

$(NAME): libft/ includes/ Makefile $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -l termcap $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $< 

re: fclean all

clean:
	make clean -C libft/
	/bin/rm -Rf $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm -Rf $(NAME)
