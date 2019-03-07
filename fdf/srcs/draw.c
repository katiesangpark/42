/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:27:22 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/06 00:30:49 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				write_pixel(t_window *window, int x, int y, int color)
{
	unsigned int	i;

	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT && x >= 0 && y >= 0)
	{
		i = (x * window->effectivebpp) + (y * window->s_l);
		*(int*)(window->framebuffer + i) = color;
	}
}

static void			draw_line(t_window *window, t_line *line)
{
	t_coord				coord;

	coord_assign(&coord, line);
	while ((coord.e2 > -coord.dx) || (coord.e2 < coord.dy))
	{
		if ((line->x >= WINDOW_WIDTH && coord.sx == 1) || (line->x < 0
			&& coord.sx == -1) || (line->y >= WINDOW_HEIGHT && coord.sy == 1)
			|| (line->y < 0 && coord.sy == -1))
			break ;
		write_pixel(window, line->x, line->y, get_color(line));
		if (line->x >= line->x1 && line->y >= line->y1)
			break ;
		coord.e2 = coord.err;
		if (coord.e2 > -coord.dx)
		{
			coord.err -= coord.dy;
			line->x += coord.sx;
		}
		if (coord.e2 < coord.dy)
		{
			coord.err += coord.dx;
			line->y += coord.sy;
		}
	}
}

static void			draw_horizontal_line(t_window *window, int i, int j)
{
	t_line	line;

	line.x0 = (WINDOW_WIDTH / 5) + (i * window->zoom) + (j * window->zoom)
				+ window->xmove;
	line.y0 = (((WINDOW_WIDTH - (WINDOW_WIDTH / 3)) + (j * window->zoom)) * 1
				/ window->zrot) - (((i * window->zoom) + (window->z
				* window->points[j][i].value)) * 1
				/ window->zrot) + window->ymove + window->extra;
	line.start_color = window->points[j][i].color;
	line.x1 = (WINDOW_WIDTH / 5) + (i * window->zoom) + ((++j)
				* window->zoom) + window->xmove;
	line.y1 = (((WINDOW_WIDTH - (WINDOW_WIDTH / 3)) + ((j) * window->zoom))
				* 1 / window->zrot) - (((i * window->zoom) + (window->z
				* window->points[j][i].value)) * 1
				/ window->zrot) + window->ymove + (window->extra / 3);
	if (window->isometric)
		isometric(&line, window->z);
	if ((line.y0 < 0 && line.y1 < 0) || (line.x0 < 0 && line.x1 < 0)
			|| (line.y0 >= WINDOW_HEIGHT && line.y1 >= WINDOW_HEIGHT)
			|| (line.x0 >= WINDOW_WIDTH && line.x1 >= WINDOW_WIDTH))
		return ;
	line.end_color = window->points[j][i].color;
	draw_line(window, &line);
}

static void			draw_vertical_line(t_window *window, int i, int j)
{
	t_line	line;

	line.x0 = (WINDOW_WIDTH / 5) + (i * window->zoom) + (j * window->zoom)
				+ window->xmove;
	line.y0 = (((WINDOW_WIDTH - (WINDOW_WIDTH / 3)) + (j * window->zoom))
				* 1 / window->zrot) - (((i * window->zoom) + (window->z
				* window->points[j][i].value)) * 1
				/ window->zrot) + window->ymove + window->extra;
	line.start_color = window->points[j][i].color;
	line.x1 = (WINDOW_WIDTH / 5) + ((++i) * window->zoom) + (j
				* window->zoom) + window->xmove;
	line.y1 = (((WINDOW_WIDTH - (WINDOW_WIDTH / 3)) + (j * window->zoom))
				* 1 / window->zrot) - ((((i) * window->zoom) + (window->z
				* window->points[j][i].value)) * 1
				/ window->zrot) + window->ymove + (window->extra / 3);
	if (window->isometric)
		isometric(&line, window->z);
	if ((line.y0 < 0 && line.y1 < 0) || (line.x0 < 0 && line.x1 < 0)
			|| (line.y0 >= WINDOW_HEIGHT && line.y1 >= WINDOW_HEIGHT)
			|| (line.x0 >= WINDOW_WIDTH && line.x1 >= WINDOW_WIDTH))
		return ;
	line.end_color = window->points[j][i].color;
	draw_line(window, &line);
}

void				draw_map(t_window *window)
{
	unsigned int		i;
	unsigned int		j;

	j = window->w;
	while (j > 0)
	{
		--j;
		i = 0;
		while (i < window->h - 1)
		{
			draw_horizontal_line(window, j, i);
			if (j < window->w - 1)
				draw_vertical_line(window, j, i);
			++i;
		}
		if (j < window->w - 1 && i < window->h)
			draw_vertical_line(window, j, i);
	}
}
