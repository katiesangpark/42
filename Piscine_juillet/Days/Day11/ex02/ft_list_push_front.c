/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:25:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/09 13:25:05 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*front;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		front = ft_create_elem(data);
		if (front != NULL)
		{
			front->next = *begin_list;
			*begin_list = front;
		}
	}
}
