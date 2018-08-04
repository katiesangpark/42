/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:35:59 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 09:42:28 by adrida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		get_square_size(const t_map *map, const int x, const int y, int *skip)
{
	int	i;
	int	size;

	size = 1;
	while (x + size <= map->h && y + size <= map->w)
	{
		i = size + 1;
		while (i--)
		{
			if (map->grid[x + i][y + size] != map->charset[CHAR_EMPTY])
			{
				*skip = size;
				return (size);
			}
			if (map->grid[x + size][y + i] != map->charset[CHAR_EMPTY])
			{
				*skip = i;
				return (size);
			}
		}
		size++;
	}
	*skip = map->w + 1;
	return (size);
}

void	save_new_square(t_square *cube, const int x, const int y,
														const int size)
{
	cube->x = x;
	cube->y = y;
	cube->size = size;
}

void	find_square(const t_map *map, t_square *cube)
{
	int	x;
	int	y;
	int	size;
	int	skip;

	x = 1;
	size = 0;
	while (x <= map->h - cube->size)
	{
		y = -1;
		while (++y <= map->w - cube->size)
		{
			if (map->grid[x][y] != map->charset[CHAR_EMPTY])
				continue ;
			size = get_square_size(map, x, y, &skip);
			if (size > cube->size)
				save_new_square(cube, x, y, size);
			if (size == map->w || size == map->h)
				return ;
			y += skip;
		}
		x++;
	}
}

int		resolve_bsq(char **grid)
{
	t_map		map;
	t_square	cube;

	if (grid == 0 || get_map_info(grid, &map) == 0)
		return (0);
	cube.x = 0;
	cube.y = 0;
	cube.size = 0;
	find_square(&map, &cube);
	if (cube.size == 0)
		return (0);
	print_resolved_map(&map, &cube);
	return (1);
}
