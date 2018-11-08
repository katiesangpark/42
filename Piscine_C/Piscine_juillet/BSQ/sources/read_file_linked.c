/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_linked.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:00:50 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/23 03:00:50 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_list	*read_file_linked(int fd)
{
	int		read_amount;
	char	buffer[BUFSIZE];
	t_list	*begin_list;
	t_list	*current;

	if (fd < 0)
		return (0);
	begin_list = 0;
	while ((read_amount = read(fd, buffer, BUFSIZE)) > 0)
	{
		if (begin_list == 0)
		{
			begin_list = ft_create_elem(ft_strndup(buffer, read_amount));
			current = begin_list;
			continue ;
		}
		current->next = ft_create_elem(ft_strndup(buffer, read_amount));
		current = current->next;
	}
	if (fd > 2)
		close(fd);
	if (read_amount == -1)
		return (0);
	return (begin_list);
}

char	*ft_strndup(char *src, int amount)
{
	int		i;
	char	*output;

	if ((output = malloc(amount + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_list_strcpy(t_list *list)
{
	int		i;
	int		x;
	int		length;
	char	*output;

	i = 0;
	length = ft_list_strlen(list);
	output = malloc(length + 1);
	while (list != 0)
	{
		x = 0;
		while (list->data[x])
		{
			output[i++] = list->data[x];
			x++;
		}
		list = list->next;
	}
	if (output[i - 1] != '\n')
		return (0);
	output[i] = '\0';
	return (output);
}

int		open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}
