/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 03:34:39 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/15 03:34:40 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelelem(t_list **alst, t_list *elem)
{
	t_list *prev;
	t_list *curr;

	if (alst == NULL || *alst == NULL || elem == NULL)
		return ;
	curr = *alst;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr == elem)
		{
			if (prev != NULL)
				prev->next = elem->next;
			else
				*alst = elem->next;
			ft_memdel(&elem->content);
			free(elem);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
