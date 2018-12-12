/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:33:55 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/07 02:33:56 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_list_push_back(t_list **begin_list, t_list *elem)
{
	t_list	*current;

	if (*begin_list == NULL)
		*begin_list = elem;
	else
	{
		current = *begin_list;
		while (current->next != NULL)
			current = current->next;
		current->next = elem;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	nlist = NULL;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (tmp == NULL)
			return (NULL);
		ft_list_push_back(&nlist, tmp);
		lst = lst->next;
	}
	return (nlist);
}
