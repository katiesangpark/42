/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:28:44 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/11 16:28:45 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		idx;
	int		fd;
	int		tmp;

	if (ac == 1)
		return (0);
	idx = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd, &line);
		if (tmp == 0)
		{
			printf("EOF\n");
			break ;
		}
		else if (tmp < 0)
		{
			printf("ERROR\n");
			break ;
		}
		printf("%d. %s\n", idx++, line);
	}
	return (0);
}
