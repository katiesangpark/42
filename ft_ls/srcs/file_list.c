/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 05:41:45 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 05:41:45 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_list.h"
#include <stdlib.h>

t_files		*file_lst_new(char *name, char *prefix)
{
	t_files *tmp;

	if (!prefix || (tmp = (t_files*)ft_memalloc(sizeof(t_files))) == NULL)
	{
		ft_strdel(&prefix);
		return (NULL);
	}
	if ((tmp->name = ft_strdup(name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	tmp->prefix = prefix;
	if ((tmp->fullpath = ft_strjoin(prefix, name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

void		files_lst_push(t_files **begin, t_files *file)
{
	t_files	*tmp;

	if (*begin == NULL)
		*begin = file;
	else
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = file;
	}
}

t_folder	*folder_lst_new(char *name, char *prefix)
{
	t_folder *tmp;

	if (!prefix || (tmp = (t_folder*)ft_memalloc(sizeof(t_folder))) == NULL)
		return (NULL);
	if ((tmp->name = ft_strdup(name)) == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->prefix = prefix;
	if ((tmp->fullpath = ft_strjoin(prefix, name)) == NULL)
	{
		ft_strdel(&prefix);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

void		folder_lst_push(t_folder **begin, t_folder *folder)
{
	t_folder	*tmp;

	if (*begin == NULL)
		*begin = folder;
	else
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = folder;
	}
}
