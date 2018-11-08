/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:59:54 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 07:59:55 by kicausse         ###   ########.fr       */
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

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list *current;

	if (begin_list1 == 0)
	{
		begin_list1 = &begin_list2;
		return ;
	}
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		ft_list_sort_(begin_list1, cmp);
		return ;
	}
	current = *begin_list1;
	while (current->next != 0)
		current = current->next;
	current->next = begin_list2;
	ft_list_sort_(begin_list1, cmp);
}
