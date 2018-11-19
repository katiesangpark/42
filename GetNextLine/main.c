/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 00:06:52 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/16 00:06:52 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		idx;
	char	*s;

	idx = 0;
	s = NULL;
	fd = open("get_next_line.c", O_RDWR);
	while ((get_next_line(fd, &s)) > 0)
	{
		printf("%d. %s\n", idx++, s);
		free(s);
	}
	return (0);
}
