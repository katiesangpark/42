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

static t_list	*get_prev_buffer(t_list **list, const int fd)
{
	t_list	*lst;

	lst = *list;
	while (lst != NULL)
	{
		if ((int)lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	return (ft_lstpush(list, "", fd));
}

static int		free_prevbuffer(t_list **prevbuffer)
{
	t_list	*list;
	t_list	*tmp;

	if (prevbuffer == NULL)
		return (-1);
	list = *prevbuffer;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		ft_memdel(&tmp->content);
	}
	*prevbuffer = NULL;
	return (-1);
}

static int		copy_to_str(t_list *current, char **line,
					t_list **prevbuffer)
{
	char	*tmp;
	char	*npos;

	if ((npos = ft_strchr(current->content, '\n')) == NULL)
	{
		*line = current->content;
		current->content = NULL;
		return (1);
	}
	if ((*line = ft_strsub(current->content,
			0, npos - (char*)current->content)) == NULL)
	{
		free(current->content);
		*line = NULL;
		return (free_prevbuffer(prevbuffer));
	}
	tmp = current->content;
	current->content = ft_strdup(npos + 1);
	free(tmp);
	return (current->content == NULL ? (free_prevbuffer(prevbuffer)) : 1);
}

static char		*append_str(char *s1, const char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				read_chars;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*prevbuffer = NULL;
	t_list			*current;

	if (fd < 0 || line == 0 || BUFF_SIZE <= 0)
		return (-1);
	if ((current = get_prev_buffer(&prevbuffer, fd)) == NULL)
		return (free_prevbuffer(&prevbuffer));
	while ((read_chars = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_chars] = '\0';
		if ((current->content = append_str(current->content, buffer)) == NULL)
			return (free_prevbuffer(&prevbuffer));
		if (ft_strchr(buffer, '\n') || read_chars < BUFF_SIZE)
			break ;
	}
	if (read_chars == 0 && current->content == NULL)
		return (read_chars);
	return (read_chars == -1 ? free_prevbuffer(&prevbuffer)
			: copy_to_str(current, line, &prevbuffer));
}
