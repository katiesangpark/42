/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:40:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/09 13:40:46 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
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
