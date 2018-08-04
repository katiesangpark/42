#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 20:19:04 by kicausse          #+#    #+#              #
#    Updated: 2018/07/21 20:19:05 by kicausse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= 	eval_expr

OBJ 	= 	main.o \
			utils.o \
			evalexpr.o

SRC 	= 	sources/main.c \
			sources/utils.c \
			sources/evalexpr.c

WFLAGS 	= 	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(WFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme: 
	norminette $(SRC)

main.o: sources/main.c
	cc -c $(WFLAGS) sources/main.c
utils.o: sources/utils.c
	cc -c $(WFLAGS) sources/utils.c
evalexpr.o: sources/evalexpr.c
	cc -c $(WFLAGS) sources/evalexpr.c

.PHONY: all re clean fclean