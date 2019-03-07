/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:19:00 by dilaouid          #+#    #+#             */
/*   Updated: 2019/02/28 11:05:47 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"
#include "parser.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int				read_lines(int fd, char **dest, int ymax)
{
	int y;
	int	data_count;

	y = 0;
	data_count = -1;
	while (get_next_line(fd, &dest[y]) > 0 && y < ymax && ft_strlen(dest[y]))
	{
		if (dest[y][0] == '#')
		{
			ft_strdel(&dest[y]);
			continue ;
		}
		if (data_count == -1)
			data_count = get_data_count(dest[y]);
		else if (data_count != get_data_count(dest[y]) || !validchars(dest[y]))
		{
			free_tab_len(dest, y);
			y = -1;
			break ;
		}
		++y;
	}
	if (y != -1)
		dest[y] = NULL;
	return (y > 0 ? y : 0);
}

static char		**get_file_data(char *filename, unsigned int *length)
{
	char	**dest;
	int		fd;
	int		newline_count;

	if ((newline_count = count_file_lines(filename)) == -1
		|| (dest = ft_memalloc(sizeof(char *) * (newline_count + 1))) == NULL)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf_fd(2, "Error: The file '%s' could not be opened.\n",
							filename);
		free(dest);
		return (NULL);
	}
	get_next_line(fd, NULL);
	*length = read_lines(fd, dest, newline_count);
	close(fd);
	return (*length == 0 ? NULL : dest);
}

static t_point	*fill_line(char *line, unsigned int *line_width)
{
	unsigned int	i;
	unsigned int	x;
	t_point			*data_line;

	if (!(data_line = ft_memalloc(sizeof(t_point) * (get_data_count(line)))))
		return (NULL);
	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			++i;
		parse_values(line + i, &data_line[x++]);
		while (line[i] && line[i] != ' ')
			++i;
		while (line[i] == ' ')
			++i;
	}
	*line_width = x;
	return (data_line);
}

int				parse_file(char *filename, t_file *file)
{
	char	**file_data;
	t_point	**points;

	if ((file_data = get_file_data(filename, &(file->h))) == NULL)
	{
		ft_printf_fd(2, "Error: Could not parse \"%s\".\n", filename);
		return (0);
	}
	points = create_tab(file_data, &(file->w));
	free_tab(file_data);
	file->points = points;
	file->name = filename;
	return (1);
}

t_point			**create_tab(char **str, unsigned int *line_width)
{
	t_point		**points;
	int			i;

	i = 0;
	while (str[i])
		++i;
	if ((points = (t_point**)ft_memalloc(sizeof(t_point*) * i)) == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if ((points[i] = fill_line(str[i], line_width)) == NULL)
		{
			while (--i >= 0)
				free(points[i]);
			free(points);
			return (0);
		}
		++i;
	}
	return (points);
}
