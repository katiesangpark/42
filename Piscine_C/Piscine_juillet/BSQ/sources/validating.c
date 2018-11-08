/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:46:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/20 11:46:06 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		get_map_info(char **grid, t_map *map)
{
	int length;
	int	line_length;

	if (grid == 0 || grid[0] == 0 || (line_length = ft_strlen(grid[0])) < 4)
		return (0);
	map->grid = grid;
	map->h = ft_atoi(grid[0], line_length - 3);
	length = tab_len(map->grid);
	if (length - 1 != map->h)
		return (0);
	ft_strncpy(map->charset, grid[0] + line_length - 3, 3);
	if (map->charset[CHAR_EMPTY] == map->charset[CHAR_OBSTACLE] ||
		map->charset[CHAR_EMPTY] == map->charset[CHAR_FULL] ||
		map->charset[CHAR_OBSTACLE] == map->charset[CHAR_FULL])
		return (0);
	return (is_map_valid(map, length));
}

int		is_map_valid(t_map *map, int length)
{
	int		i;
	int		first;

	first = -1;
	while (--length)
	{
		i = 0;
		while (map->grid[length][i])
		{
			if (!is_in_charset(map->charset, map->grid[length][i]))
				return (0);
			i++;
		}
		if (first == -1)
			first = i;
		else if (first != i)
			return (0);
	}
	map->w = first;
	return (map->w != 0 && map->h != 0);
}

int		is_in_charset(char *charset, char c)
{
	return (c == charset[CHAR_EMPTY] || c == charset[CHAR_OBSTACLE]);
}
