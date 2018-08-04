/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:50:00 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 17:37:41 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include "ft_functions.h"

int		process_file(char *file_name, int index, int argc)
{
	t_map	*map;

	if (file_name != NULL)
	{
		if (!(map = (t_map *)malloc(sizeof(t_map))))
			exit(1);
		map->file_name = file_name;
		if (!read_map(map))
			free(map);
		else
		{
			print_bsq(map);
			free(map);
			return (1);
		}
	}
	ft_putstr(2, "map error\n");
	if (index + 1 < argc)
		ft_putchar(2, '\n');
	return (0);
}

int		main(int argc, char **argv)
{
	int	index;

	if (argc < 2)
	{
		process_file(save_stdin_as_file(), 1, argc);
		return (0);
	}
	index = 1;
	while (index < argc)
	{
		if (process_file(argv[index], index, argc) && index + 1 < argc)
			ft_putchar(1, '\n');
		index++;
	}
	return (0);
}
