/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:13:19 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 07:13:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort_(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*tmp;

	if (begin_list == 0 || (current = *begin_list) == 0)
		return ;
	while (current->next != 0)
	{
		while (cmp(current->data, current->next->data) > 0)
		{
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
			current = *begin_list;
		}
		current = current->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;

	if (begin_list == 0)
		return ;
	new = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = new;
		return ;
	}
	new->next = *begin_list;
	*begin_list = new;
	ft_list_sort_(begin_list, cmp);
}
