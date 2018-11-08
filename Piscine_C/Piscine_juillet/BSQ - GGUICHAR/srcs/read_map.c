/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:16:18 by fwerner           #+#    #+#             */
/*   Updated: 2018/07/25 20:36:38 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

#define BUF_SIZE 4096

int		read_header(int file_desc, char *buffer, t_map *map)
{
	int index;

	index = 0;
	while (index == 0 || buffer[index - 1] != '\n')
	{
		if (read(file_desc, (buffer + index), 1) <= 0 || index >= BUF_SIZE)
			return (0);
		if (buffer[0] != '0')
			++index;
	}
	if (index < 4
			|| (map->height = atoi_map(buffer, index - 4)) <= 0
			|| fill_map_chars((buffer + index - 4), map) == 0)
		return (0);
	index = 0;
	while (buffer[0] != '\n')
	{
		if (read(file_desc, buffer, 1) <= 0)
			return (0);
		++index;
	}
	if (index <= 1)
		return (0);
	map->width = (index - 1);
	return (1);
}

int		read_line_for_file(t_map *map, t_bufs *buf, unsigned int line_count
		, int line_size)
{
	int		index;

	index = 0;
	while (index < (line_size - 1))
	{
		if ((buf->chars)[index] == map->obstacle)
			(buf->ints)[index] = 0;
		else if ((buf->chars)[index] == map->empty)
		{
			write_case_val(buf->ints, buf->last_ints, index);
			if ((buf->ints)[index] > map->best.size)
			{
				map->best.size = (buf->ints)[index];
				map->best.x = index + 1 - map->best.size;
				map->best.y = line_count - map->best.size;
			}
		}
		else
			return (0);
		++index;
	}
	return (1);
}

int		read_file_for_find(int file_desc, t_map *map, t_bufs *buf)
{
	int				size_read;
	unsigned int	line_count;

	line_count = 0;
	while ((size_read = read(file_desc, buf->chars, map->width + 1)) > 0
			&& line_count <= map->height)
	{
		if (((unsigned int)size_read) < (map->width + 1)
				|| (buf->chars)[map->width] != '\n')
			return (0);
		++line_count;
		if (read_line_for_file(map, buf, line_count, size_read) == 0)
			return (0);
		swap_buf(&(buf->ints), &(buf->last_ints));
	}
	if (size_read < 0 || line_count != map->height)
		return (0);
	return (1);
}

int		find_best_with_file(int file_desc, t_map *map)
{
	t_bufs			buf;
	unsigned int	index;
	int				error;

	index = 0;
	error = 0;
	map->best.size = 0;
	buf.chars = malloc(sizeof(*(buf.chars)) * map->width);
	buf.ints = malloc(sizeof(*(buf.ints)) * map->width);
	buf.last_ints = malloc(sizeof(*(buf.last_ints)) * map->width);
	if (buf.chars == NULL || buf.ints == NULL || buf.last_ints == NULL)
		exit(1);
	while (index < map->width)
		(buf.last_ints)[index++] = 0;
	if (read_file_for_find(file_desc, map, &buf) == 0)
		error = 1;
	free(buf.chars);
	free(buf.ints);
	free(buf.last_ints);
	return (!error);
}

int		read_map(t_map *map)
{
	char	buffer[BUF_SIZE];
	int		file_desc;

	file_desc = open(map->file_name, O_RDONLY);
	if (file_desc == -1)
		return (0);
	if (read_header(file_desc, buffer, map) == 0)
		return (0);
	close(file_desc);
	file_desc = open(map->file_name, O_RDONLY);
	if (file_desc == -1)
		return (0);
	buffer[0] = '\0';
	while (buffer[0] != '\n')
		if (read(file_desc, buffer, 1) <= 0)
			return (0);
	if (find_best_with_file(file_desc, map) == 0)
		return (0);
	close(file_desc);
	return (1);
}
