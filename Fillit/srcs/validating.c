/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 08:16:02 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/25 08:16:03 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		validate_block_shapes(t_block *block)
{
	int	i;
	int	ct;
	int	count;

	while (block != 0)
	{
		i = -1;
		count = 0;
		ct = 0;
		while (++i < 16 && count <= 4)
		{
			if (ft_get_bit(block->data, i) == 0)
				continue;
			count++;
			ct += (i + 4 < 16 && ft_get_bit(block->data, i + 4)) \
					+ (i - 4 >= 0 && ft_get_bit(block->data, i - 4)) \
					+ (i % 4 > 0 && ft_get_bit(block->data, i - 1)) \
					+ (i % 4 < 3 && ft_get_bit(block->data, i + 1));
		}
		if ((ct != 8 && ct != 6) || count != 4 || i != 16)
			return (0);
		block = block->next;
	}
	return (1);
}

int		move_bits(int nbr, int leftmost, int upmost)
{
	int tmp;

	if (leftmost == upmost)
	{
		while (leftmost-- != 0)
			nbr /= 2;
	}
	else
	{
		tmp = leftmost % 4;
		while (tmp-- != 0)
			nbr /= 2;
		tmp = upmost / 4;
		while (tmp-- != 0)
			nbr /= 16;
	}
	return (nbr);
}

void	get_block_size(t_block *block)
{
	int	i;
	int	rightmost;
	int	downmost;

	i = 0;
	rightmost = 0;
	downmost = 0;
	while (i < 16)
	{
		if (ft_get_bit(block->data, i) == 1 \
			&& i % 4 > rightmost % 4)
			rightmost = i;
		if (ft_get_bit(block->data, i) == 1 \
			&& i / 4 > downmost / 4)
			downmost = i;
		i++;
	}
	block->w = rightmost % 4;
	block->h = downmost / 4;
}

int		correct_blocks_starting_pos(t_block *block)
{
	int	i;
	int	leftmost;
	int	upmost;

	while (block != 0)
	{
		i = 0;
		leftmost = 15;
		upmost = 15;
		while (i < 16)
		{
			if (ft_get_bit(block->data, i) == 1 \
				&& i % 4 < leftmost % 4)
				leftmost = i;
			if (ft_get_bit(block->data, i) == 1 \
				&& i / 4 < upmost / 4)
				upmost = i;
			i++;
		}
		block->data = move_bits(block->data, leftmost, upmost);
		get_block_size(block);
		block = block->next;
	}
	return (1);
}
