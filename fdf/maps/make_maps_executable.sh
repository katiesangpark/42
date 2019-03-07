#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make_maps_executable.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kicausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 07:14:09 by kicausse          #+#    #+#              #
#    Updated: 2019/03/06 07:18:50 by kicausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export IFS=$'\n'
for file in $(find . -name '*.fdf')
do
	if [[ $(pwd) == *"maps"* ]]
	then
		echo '#!'$(pwd)/../fdf > $file"_tmp"
	else
		echo '#!'$(pwd)/fdf > $file"_tmp"
	fi
	cat $file >> $file"_tmp"
	rm $file
	mv $file"_tmp" $file
	chmod 755 $file
done