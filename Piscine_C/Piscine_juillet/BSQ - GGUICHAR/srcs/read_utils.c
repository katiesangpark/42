/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:02:37 by fwerner           #+#    #+#             */
/*   Updated: 2018/07/25 21:50:56 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"

#define BUF_SIZE 4096
#define STDIN_FILE "stdin.cpy"

void	swap_buf(unsigned int **buf, unsigned int **last_buf)
{
	unsigned int	*tmp;

	tmp = *buf;
	*buf = *last_buf;
	*last_buf = tmp;
}

void	write_case_val(unsigned int *buf, unsigned int *last_buf, int index)
{
	unsigned int	min;

	if (index == 0)
		min = 0;
	else
	{
		min = last_buf[index];
		if (last_buf[index - 1] < min)
			min = last_buf[index - 1];
		if (buf[index - 1] < min)
			min = buf[index - 1];
	}
	buf[index] = min + 1;
}

int		read_stdin_header(char *buffer)
{
	int index;

	index = 0;
	while (index == 0 || buffer[index - 1] != '\n')
	{
		if (read(0, buffer + index, 1) <= 0 || index >= BUF_SIZE)
			return (0);
		if (buffer[0] != '0')
			index++;
	}
	return (index);
}

char	*save_stdin_as_file(void)
{
	t_map	map;
	char	buffer[BUF_SIZE];
	int		file_desc;
	int		size_read;
	int		index;

	index = read_stdin_header(buffer);
	if (index < 4 || !atoi_map(buffer, index - 4)
			|| !fill_map_chars(buffer + index - 4, &map))
		return (NULL);
	file_desc = open(STDIN_FILE
			, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_desc == -1 || write(file_desc, buffer, index) != index)
		exit(1);
	while ((size_read = read(0, buffer, BUF_SIZE)) > 0)
	{
		if (buffer[0] != '\n'
				&& buffer[0] != map.empty && buffer[0] != map.obstacle)
			return (NULL);
		if (write(file_desc, buffer, size_read) != size_read)
			exit(1);
	}
	if (close(file_desc) < 0)
		exit(1);
	return (STDIN_FILE);
}
