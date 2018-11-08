# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 00:18:25 by cgilbert          #+#    #+#              #
#    Updated: 2018/07/14 00:20:02 by cgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= 	sources/main.c \
		sources/copy.c \
		sources/optimization.c \
		sources/printing.c \
		sources/validating.c
		
OBJ 	= 	main.o \
		copy.o \
		optimization.o \
		printing.o \
		validating.o

$(NAME): all

all:
	cc -Iincludes -Wall -Wextra -Werror $(OBJ) -o colle-1

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f colle-1
	
re:	fclean all

main.o: sources/main.c
	cc -c $(WFLAGS) sources/main.c
copy.o: sources/copy.c
	cc -c $(WFLAGS) sources/copy.c
optimization.o: sources/optimization.c
	cc -c $(WFLAGS) sources/optimization.c
printing.o: sources/printing.c
	cc -c $(WFLAGS) sources/printing.c
validating.o: sources/validating.c
	cc -c $(WFLAGS) sources/validating.c
	
.PHONY: all re clean fclean
