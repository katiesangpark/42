/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:14:51 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/20 09:14:52 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

void	fill_resolved_map(t_map *map, t_square *cube)
{
	int		x;
	int		y;
	char	**grid;
	char	fullchar;

	x = cube->x;
	grid = map->grid;
	fullchar = map->charset[CHAR_FULL];
	while (x < cube->x + cube->size)
	{
		y = cube->y;
		while (y < cube->y + cube->size)
		{
			grid[x][y] = fullchar;
			y++;
		}
		x++;
	}
}

void	print_resolved_map(t_map *map, t_square *cube)
{
	int	x;

	fill_resolved_map(map, cube);
	x = 1;
	while (x <= map->h)
	{
		write(1, map->grid[x++], map->w);
		write(1, "\n", 1);
	}
}
