/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:28:55 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/08 06:28:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *output;

	output = NULL;
	while (1)
	{
		get_next_line(fd, &output);
		printf("%s\n", output);
		break;
	}
	return 0;
}