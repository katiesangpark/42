/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:25:04 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/11 16:25:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static int	get_line_end(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == EOF || s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		read_chars;

	if (fd < 0 || line == 0)
		return (-1);
	while (1)
	{
		read_chars = read(fd, buffer, BUFF_SIZE);
		buffer[read_chars > 0 ? read_chars : 0] = '\0';
		if (read_chars <= 0)
			return (read_chars);
		if (get_line_end(buffer) != -1)
		{
			*line = ft_strsub(buffer, 0, get_line_end(buffer));
			break ;
		}
	}
	return (1);
}
