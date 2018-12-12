/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:51:41 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/25 09:51:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		overlap(t_block *curr, t_block *block)
{
	register int data;
	register int x;
	register int y;

	while (curr != block)
	{
		x = curr->x - block->x;
		y = curr->y - block->y;
		if (x <= block->w && y <= block->h)
		{
			data = block->data;
			data = (x >= 0) ? ((data >> x) & (0xF >> x)) | ((data >> x) \
			& 0xF0 & (0xF0 >> x)) | ((data >> x) & 0xF00 & (0xF00 >> x)) \
			| ((data >> x) & 0xF000) : ((data << -x) & 0xF) | ((data << -x) \
			& 0xF0 & (0xF0 << -x)) | ((data << -x) & 0xF00 & (0xF00 << -x)) \
			| ((data << -x) & (0xF000 << -x));
			if (((y >= 0) ? (data >> (y << 2)) : (data << (-y << 2))) \
				& curr->data)
				return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void stuff(t_block *block)
{
	if (!block)
		return ;
	stuff(block->next);
	block->prevx = 0;
	block->prevy = 0;
}


int		solve2(t_block *beginlist, t_block *block, int map_size)
{
	newblock: while (block != 0)
	{
		block->y = 0;
		while (block->y + block->h < map_size)
		{
			block->x = 0;
			overlapcheck: while (block->x + block->w < map_size)
			{
				if (!overlap(beginlist, block))
				{
					block = block->next;
					goto newblock;
				}
				++block->x;
			}
			++block->y;
		}
		if (block->prev != 0)
		{
			block = block->prev;
			++block->x;
			goto overlapcheck;
		}
		++map_size;
	}
	return (map_size);
}

int		solve(t_block *beginlist, t_block *block, const int map_size)
{
	const int h = block->h;
	const int w = block->w;

	block->y = 0;
	while (block->y + h < map_size)
	{
		block->x = 0;
		while (block->x + w < map_size)
		{
			if (!overlap(beginlist, block) && (!block->next || \
				solve(beginlist, block->next, map_size)))
				return (map_size);
			++block->x;
		}
		++block->y;
	}
	return (beginlist == block ? solve(beginlist, beginlist, map_size + 1) : 0);
}
