/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:48:32 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/26 05:26:16 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

t_block		*lst_new(int data)
{
	t_block	*tmp;

	if ((tmp = (t_block*)ft_memalloc(sizeof(t_block))) == NULL)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->x = DEFAULT_POS;
	tmp->y = DEFAULT_POS;
	tmp->w = 1;
	tmp->h = 1;
	return (tmp);
}

t_block		*lst_push(t_block **begin_list, int data)
{
	t_block	*tmp;
	t_block	*tmp2;

	if (begin_list == NULL || (tmp = lst_new(data)) == NULL)
		return (NULL);
	if (*begin_list == NULL)
		*begin_list = tmp;
	else
	{
		tmp2 = *begin_list;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (tmp);
}

void		lst_clear(t_block *lst)
{
	t_block	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int			lst_index(const t_block *begin, t_block *elem)
{
	int i;

	i = 0;
	while (begin != NULL)
	{
		if (elem == begin)
			return (i);
		i++;
		begin = begin->next;
	}
	return (0);
}

int			lst_size(t_block *elem)
{
	int i;

	i = 0;
	while (elem != NULL)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
