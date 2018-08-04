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

$(NAME): all

all:
	cc -Iincludes -Wall -Wextra -Werror -o colle-1 sources/*.c

test:
	cc -Iincludes -o a.out sources/*.c

clean:
	/bin/rm -f a.out

fclean: clean
	/bin/rm -f colle-1