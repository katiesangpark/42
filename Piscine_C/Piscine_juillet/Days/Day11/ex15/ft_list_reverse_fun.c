/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 06:40:40 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/10 06:40:41 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_get_size(t_list *begin_list)
{
	t_list	*current;
	int		i;

	i = 0;
	current = begin_list;
	while (current != 0)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_list	*ft_list_element_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	i = 0;
	current = begin_list;
	while (current != 0 && i < nbr)
	{
		current = current->next;
		i++;
	}
	return ((i == nbr) ? current : 0);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	void	*tmp;
	int		i;
	int		list_size;

	if (begin_list == 0)
		return ;
	i = 0;
	list_size = ft_list_get_size(begin_list) - 1;
	while (i <= list_size / 2)
	{
		tmp = ft_list_element_at(begin_list, i)->data;
		ft_list_element_at(begin_list, i)->data = \
							ft_list_element_at(begin_list, list_size - i)->data;
		ft_list_element_at(begin_list, list_size - i)->data = tmp;
		i++;
	}
}
