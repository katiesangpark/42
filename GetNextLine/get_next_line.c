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
#include "libft.h"
#include <unistd.h>

#include <stdio.h>

static int	get_line_end(const char *s, int maxlen)
{
	int	i;

	i = 0;
	while (s[i] != EOF && s[i] != '\n' && i != maxlen)
		i++;
	if (s[i] == EOF || s[i] == '\n')
		return (i);
	return (-1);
}

static int	check_previous_buffer(t_list *prevbuff, int *read_chars)
{
	int		npos;
	int		line_len;

	npos = 0;
	if (read_chars != NULL && prevbuff != NULL)
	{
		*read_chars = 0;
		npos = get_line_end(prevbuff->content, prevbuff->content_size);
		if (npos != -1)
			*read_chars = -2;
	}
	else if (prevbuff != NULL && read_chars == NULL)
	{
		line_len = -1;
		while (line_len == -1 && prevbuff != NULL)
		{
			line_len = get_line_end(prevbuff->content, prevbuff->content_size);
			npos += (line_len == -1 ? prevbuff->content_size : line_len);
			prevbuff = prevbuff->next;
		}
	}
	return (npos);
}

static char	*ft_list_to_str(t_list *list)
{
	char			*output;
	int				len;
	int				line_len;

	len = check_previous_buffer(list, NULL);
	if ((output = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	len = 0;
	line_len = -1;
	while (line_len == -1 && list != NULL)
	{
		line_len = get_line_end(list->content, list->content_size);
		ft_memcpy(output + len, list->content,
			(line_len == -1 ? list->content_size : line_len));
		len += (line_len == -1 ? list->content_size : line_len);
		list = list->next;
	}
	output[len] = '\0';
	return (output);
}

static void	ft_list_shorten(t_list **list)
{
	char	*tmp;
	int		npos;

	if (*list == NULL)
		return ;
	while ((*list)->next != NULL)
	{
		tmp = (char*)(*list);
		(*list) = (*list)->next;
		free(tmp);
	}
	tmp = (*list)->content;
	npos = get_line_end(tmp, (*list)->content_size);
	if (npos != -1)
	{
		tmp += npos + 1;
		(*list)->content = tmp;
		(*list)->content_size = (*list)->content_size - npos - 1;
	}
	else
	{
		free((*list)->content);
		free(*list);
		*list = NULL;
	}
}

int			get_next_line(const int fd, char **line)
{
	int				read_chars;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*prevbuffer = NULL;

	if (fd < 0 || line == 0)
		return (-1);
	check_previous_buffer(prevbuffer, &read_chars);
	while (read_chars != -2)
	{
		read_chars = read(fd, buffer, BUFF_SIZE);
		buffer[read_chars > 0 ? read_chars : 0] = EOF;
		ft_lstpush(&prevbuffer,
			ft_strsub(buffer, 0, read_chars), read_chars);
		if (read_chars <= 0)
			return (read_chars);
		if (get_line_end(buffer, read_chars - 1) != -1)
			break ;
	}
	*line = ft_list_to_str(prevbuffer);
	ft_list_shorten(&prevbuffer);
	return (1);
}
