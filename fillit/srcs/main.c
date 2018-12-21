/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 06:42:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/22 06:42:06 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

int		main(int ac, char **argv)
{
	t_block	*blocks;
	int		map_size;

	if (ac == 1)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	blocks = NULL;
	if (!read_file(argv[1], &blocks) || !validate_block_shapes(blocks))
	{
		lst_clear(blocks);
		ft_putendl("error");
		return (0);
	}
	correct_blocks_starting_pos(blocks);
	map_size = ft_sqrt(lst_size(blocks) * 4);
	map_size = (int)solve(blocks, blocks, (char)map_size);
	print_map(blocks, map_size);
	lst_clear(blocks);
	return (0);
}
