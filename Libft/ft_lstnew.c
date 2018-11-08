/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:06:57 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/07 02:06:57 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == 0)
		return (0);
	if (content == NULL)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		list->content = (unsigned char*)malloc(content_size);
		list->content_size = content_size;
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
