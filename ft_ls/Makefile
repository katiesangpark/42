# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <kicausse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:08:47 by kicausse          #+#    #+#              #
#    Updated: 2018/12/05 23:26:12 by kicausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	ft_ls

SRC 	= 	srcs/args.c srcs/args_struct.c srcs/conditions.c srcs/file_list.c  \
			srcs/free.c srcs/ft_ls.c srcs/get_info.c srcs/list_utils.c  \
			srcs/print_inline.c srcs/print_list.c srcs/printing.c  \
			srcs/printing_utils.c srcs/sort.c srcs/sort_reverse.c srcs/utils.c \
			srcs/sort_alphabetical.c srcs/get_info_2.c srcs/sort_access_time.c

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft -Iincludes

all: libft/ $(NAME)

$(NAME): $(OBJ) libft/ Makefile
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
