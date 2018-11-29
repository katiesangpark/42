/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:29:53 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/27 16:29:53 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		get_bit_from_coords(const int data, const int x, const int y)
{
	if (x < 0 || y < 0 || x >= 4 || y >= 4)
		return (0);
	return (ft_get_bit(data, x + (y * 4)));
}

char	get_char_from_coords(t_block *blocks, const int x, const int y)
{
	t_block		*curr;

	curr = blocks;
	while (curr != NULL)
	{
		if (x >= curr->x && x <= curr->x + curr->w \
			&& y >= curr->y && y <= curr->y + curr->h \
			&& get_bit_from_coords(curr->data, x - curr->x, y - curr->y))
		{
			return (CHARSET[lst_index(blocks, curr)]);
		}
		curr = curr->next;
	}
	return ('.');
}

void	print_map_slow(t_block *blocks, const int map_size)
{
	int		x;
	int		y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			ft_putchar(get_char_from_coords(blocks, x, y));
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	print_map(t_block *blocks, const int map_size)
{
	char	*line;
	int		x;
	int		y;
	int		idx;

	if (!(line = ft_strnew((size_t)(map_size * map_size + map_size) + 1)))
		print_map_slow(blocks, map_size);
	else
	{
		idx = 0;
		y = 0;
		while (y < map_size)
		{
			x = 0;
			while (x < map_size)
			{
				line[idx++] = get_char_from_coords(blocks, x, y);
				x++;
			}
			line[idx++] = '\n';
			y++;
		}
		ft_putstr(line);
		free(line);
	}
}
