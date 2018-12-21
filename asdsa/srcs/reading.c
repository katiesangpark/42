/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:13:04 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/25 07:13:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

int		is_line_valid(char *line, int strict)
{
	unsigned int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#' && line[i] != '\n')
			return (0);
		if (line[i] == '\n' && i % 5 != 4 && i < 20)
			return (0);
		if (line[i] != '\n' && i % 5 == 4)
			return (0);
		if (line[i] != '\n' && i == 20)
			return (0);
		i++;
	}
	return ((strict == 1) ? (i == 20) : (i == 21 || i == 20));
}

int		str_to_data(char *str)
{
	int		i;
	int		data;

	i = 0;
	data = 0;
	while (str[i])
	{
		if (str[i] == '#')
			data = ft_set_bit(data, i - i / 5, 1);
		i++;
	}
	return (data);
}

int		read_file(char *filename, t_block **out)
{
	int		fd;
	ssize_t	ret;
	char	buff[CONST_BUF_SIZE + 1];
	int		size;

	if (out == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	size = 0;
	while ((ret = read(fd, buff, CONST_BUF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!is_line_valid(buff, 0))
			return (0);
		if (lst_push(out, str_to_data(buff)) == NULL \
			|| ++size >= MAX_TETR_NBR)
			return (0);
	}
	if (ret == -1)
		return (0);
	return (is_line_valid(buff, 1));
}
