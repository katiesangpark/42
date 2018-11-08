/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:36:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/09 16:36:46 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)())
{
	t_list	*current;

	current = begin_list;
	while (current != 0)
	{
		if (cmp(current->data, data_ref) == 0)
			f(current->data);
		current = current->next;
	}
}
