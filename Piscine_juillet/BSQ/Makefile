#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 08:45:39 by kicausse          #+#    #+#              #
#    Updated: 2018/07/20 08:45:40 by kicausse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= 	bsq

OBJ 	= 	main.o \
			read_file_linked.o \
			split.o \
			utils.o \
			validating.o \
			bsq.o \
			print.o \
			list.o  

SRC 	= 	sources/main.c \
			sources/read_file_linked.c \
			sources/split.c \
			sources/utils.c \
			sources/validating.c \
			sources/bsq.c \
			sources/print.c \
			sources/list.c 

INCL 	= 	-Iincludes
WFLAGS 	= 	$(INCL) -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cc $(WFLAGS) $(OBJ) -o $(NAME)

test: $(OBJ)
	cc $(INCL) $(OBJ) -o $(NAME)

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
read_file_linked.o: sources/read_file_linked.c
	cc -c $(WFLAGS) sources/read_file_linked.c
split.o: sources/split.c
	cc -c $(WFLAGS) sources/split.c
utils.o: sources/utils.c
	cc -c $(WFLAGS) sources/utils.c
validating.o: sources/validating.c
	cc -c $(WFLAGS) sources/validating.c
bsq.o: sources/bsq.c
	cc -c $(WFLAGS) sources/bsq.c
print.o: sources/print.c
	cc -c $(WFLAGS) sources/print.c
list.o: sources/list.c
	cc -c $(WFLAGS) sources/list.c

.PHONY: all re clean fclean norme test