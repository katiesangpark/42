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

static char	*ft_list_to_str(t_list *list)
{
	t_list			*tmp;
	char			*output;
	int				len;
	int				line_len;

	tmp = list;
	len = 0;
	line_len = -1;
	while (line_len == -1 && tmp != NULL)
	{
		line_len = get_line_end(tmp->content, tmp->content_size);
		len += (line_len == -1 ? tmp->content_size : line_len);
		tmp = tmp->next;
	}
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
		tmp = (char*)*list;
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
	while (1)
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
