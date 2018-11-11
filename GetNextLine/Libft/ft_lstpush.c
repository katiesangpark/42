/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:21:29 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/11 19:21:30 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **begin_list, void *content, int content_size)
{
	t_list	*current;

	if (*begin_list == NULL)
		*begin_list = ft_lstnew(content, content_size);
	else
	{
		current = *begin_list;
		while (current->next != NULL)
			current = current->next;
		current->next = ft_lstnew(content, content_size);
	}
}
