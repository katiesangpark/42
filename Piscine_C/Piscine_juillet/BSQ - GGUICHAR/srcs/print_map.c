/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:11:50 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 21:02:30 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft_functions.h"

void	print_bsq_fast(t_map *map, t_print *print)
{
	if (print->current_y < map->best.y
			|| print->current_y > map->best.y + map->best.size - 1)
	{
		write(1, print->buffer, print->size);
	}
	else
	{
		if (map->best.x > 0)
			write(1, print->buffer, map->best.x);
		write(1, print->square, map->best.size);
		write(1, print->buffer + map->best.x + map->best.size
				, print->size - (map->best.x + map->best.size));
	}
}

void	print_with_read(int fd, t_map *map)
{
	t_print			print;
	unsigned int	i;

	if (!(print.buffer = malloc(sizeof(char) * (map->width + 1)))
			|| !(print.square = malloc(sizeof(char) * map->best.size + 1)))
		exit(1);
	i = 0;
	while (i < map->best.size)
	{
		print.square[i] = map->full;
		i++;
	}
	while (read(fd, print.buffer, 1) > 0 && print.buffer[0] != '\n')
		continue ;
	print.current_y = 0;
	while ((print.size = read(fd, print.buffer, map->width + 1)) > 0)
	{
		print_bsq_fast(map, &print);
		print.current_y++;
	}
	free(print.buffer);
	free(print.square);
}

void	print_bsq(t_map *map)
{
	int	fd;

	fd = open(map->file_name, O_RDONLY);
	if (fd == -1)
		return ;
	print_with_read(fd, map);
	close(fd);
}
