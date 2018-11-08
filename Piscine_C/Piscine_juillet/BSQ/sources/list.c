/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:54:17 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/23 03:54:17 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_list	*ft_create_elem(char *data)
{
	t_list *output;

	output = malloc(sizeof(t_list));
	if (output != NULL)
	{
		output->data = data;
		output->next = NULL;
	}
	return (output);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*current;
	t_list	*previous;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	current = *begin_list;
	while (current != 0)
	{
		previous = current;
		current = current->next;
		if (previous->data != 0)
			free(previous->data);
		free(previous);
	}
	*begin_list = 0;
}

int		ft_list_strlen(t_list *list)
{
	int		i;
	int		length;

	length = 0;
	while (list != 0)
	{
		i = 0;
		while (list->data[i])
			i++;
		length += i;
		list = list->next;
	}
	return (length);
}
