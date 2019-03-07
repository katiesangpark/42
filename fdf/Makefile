# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 23:49:44 by kicausse          #+#    #+#              #
#    Updated: 2019/03/06 00:22:52 by dilaouid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fdf

SRC 	= 	srcs/main.c srcs/parser.c srcs/parser_utils.c srcs/window.c \
			srcs/utils.c srcs/keyhandler.c srcs/draw.c srcs/hud.c srcs/coord.c \
			srcs/isometric.c srcs/gradients.c

INC 	= 	includes/fdf.h

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft -Iincludes -Iminilibx_macos

all: $(NAME) libft/

$(NAME): libft/ includes/ Makefile $(OBJ)
	make -C libft
	$(CC) -I /usr/local/include $(OBJ) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $< 

re: fclean all

clean:
	make clean -C libft/
	/bin/rm -Rf $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm -Rf $(NAME)
