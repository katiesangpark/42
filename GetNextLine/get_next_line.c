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

static char	*realloc_str(char *source, int memsize)
{
	int		i;
	char	*output;

	i = 0;
	if ((output = malloc(memsize)) == NULL)
	{
		free(source);
		return (NULL);
	}
	i = 0;
	while (source[i] && i < memsize - 1)
	{
		output[i] = source[i];
		i++;
	}
	free(source);
	output[i] = '\0';
	return (output);
}

static int	read_line(const int fd, char **buffer)
{
	int		buf_size;
	int		idx;
	int		read_chars;

	buf_size = BUFF_SIZE;
	if (buf_size == 0 || (*buffer = (char*)malloc(buf_size)) == NULL)
		return (ERR_ALLOC_FAIL);
	idx = 0;
	while ((read_chars = read(fd, (*buffer) + idx, 1)) > 0)
	{
		if ((*buffer)[idx] == '\n')
			break ;
		idx++;
		if (idx + 1 >= buf_size)
			*buffer = realloc_str(*buffer, buf_size *= 2);
		if (*buffer == 0)
			return (ERR_ALLOC_FAIL);
	}
	if (read_chars <= 0)
		return ((read_chars == ERR_FILE_END) ? ERR_FILE_END : ERR_READ_FAIL);
	*buffer = realloc_str(*buffer, idx + 1);
	return (ERR_SUCCESS);
}

int			get_next_line(const int fd, char **line)
{
	char	*output;
	int		errcode;

	errcode = read_line(fd, &output);
	if (errcode == ERR_ALLOC_FAIL || errcode == ERR_READ_FAIL)
	{
		if (errcode == ERR_READ_FAIL)
			free(output);
		return (-1);
	}
	if (errcode != ERR_FILE_END)
		*line = output;
	return (errcode);
}
