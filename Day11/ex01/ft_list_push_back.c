/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcausse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:42:04 by kcausse           #+#    #+#             */
/*   Updated: 2018/02/14 22:42:04 by kcausse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, char *data)
{
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		t_list *list;
		
		list = *begin_list;
		while (list->next != NULL)
			list = list->next;
		list->next = ft_create_elem(data);
	}
}
