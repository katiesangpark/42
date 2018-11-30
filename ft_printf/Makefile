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

SRC 	= 	libft/ft_abs.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_ceil.c \
			libft/ft_floor.c libft/ft_get_bit.c libft/ft_isalnum.c libft/ft_isalpha.c \
			libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c \
			libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelelem.c \
			libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
			libft/ft_lstnew.c libft/ft_lstpush.c libft/ft_max.c libft/ft_memalloc.c \
			libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
			libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_min.c \
			libft/ft_print_hex.c libft/ft_print_memory.c libft/ft_putchar.c \
			libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c \
			libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putnbrendl.c \
			libft/ft_putnstr.c libft/ft_putstr.c libft/ft_putstr_fd.c \
			libft/ft_putstr_non_printable.c libft/ft_realloc.c libft/ft_set_bit.c \
			libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c \
			libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c \
			libft/ft_strins.c libft/ft_striter.c libft/ft_striteri.c \
			libft/ft_strjoin.c libft/ft_strjoinfree.c libft/ft_strlcat.c \
			libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c \
			libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c \
			libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c \
			libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtolower.c \
			libft/ft_strtoupper.c libft/ft_strtrim.c libft/ft_tolower.c \
			libft/ft_toupper.c srcs/ft_printf.c srcs/functions_hub.c srcs/lists.c \
			srcs/options.c srcs/print_nbr.c srcs/utils.c

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
