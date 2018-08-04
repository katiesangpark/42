/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:37:19 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 16:31:42 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	atoi_map(char *header, int size)
{
	int				index;
	unsigned int	result;
	unsigned int	old_result;

	index = 0;
	result = 0;
	old_result = 0;
	while (index < size)
	{
		if (header[index] < '0' || header[index] > '9')
			return (0);
		result *= 10;
		if (result < old_result)
			return (0);
		old_result = result;
		result += header[index] - '0';
		if (result < old_result)
			return (0);
		old_result = result;
		index++;
	}
	return (result);
}

int				check_map_chars(char *ptr)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 3)
	{
		j = 0;
		count = 0;
		while (j < 3)
		{
			if (ptr[i] == ptr[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

int				fill_map_chars(char *ptr, t_map *map)
{
	if (!check_map_chars(ptr))
		return (0);
	map->empty = ptr[0];
	map->obstacle = ptr[1];
	map->full = ptr[2];
	return (1);
}
