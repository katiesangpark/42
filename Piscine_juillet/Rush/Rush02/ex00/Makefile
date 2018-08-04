# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 15:05:47 by phaydont          #+#    #+#              #
#    Updated: 2018/07/21 15:16:12 by phaydont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	colle-2

OBJ 	= 	main.o \
			read_file.o \
			split.o \
			utils.o \
			identifying.o \
			printing.o \
			string_utils.o \
			shapes.o \
			rectangle.o \
			diff.o 

SRC 	= 	sources/main.c \
			sources/read_file.c \
			sources/split.c \
			sources/utils.c \
			sources/identifying.c \
			sources/printing.c \
			sources/string_utils.c \
			sources/diff.c \
			sources/shapes.c \
			sources/shapes/rectangle.c 

WFLAGS 	= 	-Iincludes -Wall -Wextra -Werror 

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
read_file.o: sources/read_file.c
	cc -c $(WFLAGS) sources/read_file.c
split.o: sources/split.c
	cc -c $(WFLAGS) sources/split.c
utils.o: sources/utils.c
	cc -c $(WFLAGS) sources/utils.c
identifying.o: sources/identifying.c
	cc -c $(WFLAGS) sources/identifying.c
printing.o: sources/printing.c
	cc -c $(WFLAGS) sources/printing.c
string_utils.o: sources/string_utils.c
	cc -c $(WFLAGS) sources/string_utils.c
diff.o: sources/diff.c
	cc -c $(WFLAGS) sources/diff.c
shapes.o: sources/shapes.c
	cc -c $(WFLAGS) sources/shapes.c
rectangle.o: sources/shapes/rectangle.c
	cc -c $(WFLAGS) sources/shapes/rectangle.c

.PHONY: all re clean fclean