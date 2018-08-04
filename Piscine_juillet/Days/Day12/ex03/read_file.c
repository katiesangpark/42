/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:35:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 08:35:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*get_file(char *filename)
{
	int		fd;
	int		read_amount;
	char	buffer[BUFSIZE];
	char	*output;

	fd = open(filename, O_RDONLY);
	output = malloc(1);
	output[0] = 0;
	while (output && (read_amount = read(fd, buffer, BUFSIZE)) > 0)
		concat_strings(&output, buffer, read_amount);
	return (output);
}

void	concat_strings(char **dest, char *src, int amount)
{
	int		i;
	int		dest_len;
	char	*tmp;

	dest_len = 0;
	while ((*dest)[dest_len])
		dest_len++;
	if ((tmp = malloc(dest_len + amount + 1)) == NULL)
		return ;
	i = 0;
	while (i < dest_len)
	{
		tmp[i] = (*dest)[i];
		i++;
	}
	i = 0;
	while (i < amount)
	{
		tmp[dest_len + i] = src[i];
		i++;
	}
	tmp[dest_len + i] = '\0';
	free(*dest);
	*dest = tmp;
}

int		file_exists(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (fd);
	close(fd);
	return (1);
}
