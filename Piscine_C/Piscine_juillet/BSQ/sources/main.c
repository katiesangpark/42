/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:52:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/20 08:52:27 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	handle_file_linked(int fd)
{
	char	*map;
	t_list	*file;
	char	**grid;

	file = read_file_linked(fd);
	map = ft_list_strcpy(file);
	if (file != 0)
		ft_list_clear(&file);
    if (fd > 2 && map != 0)
	{
		grid = split(map);
		destroy_map(map);
		if (resolve_bsq(grid) == 0)
			print_error("map error\n");
		destroy_grid(grid);
	}
    else
        print_error("map error\n");
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc == 1)
		handle_file_linked(0);
	i = 1;
	while (i < argc)
	{
		fd = open_file(argv[i]);
		handle_file_linked(fd);
        if (++i != argc)
            print("\n");
	}
	return (0);
}
