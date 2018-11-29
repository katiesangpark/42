/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:17:25 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 20:17:26 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include <stdlib.h>

t_specifier		*spec_lst_new(char option, char *flag)
{
	t_specifier	*tmp;

	if ((tmp = (t_specifier*)malloc(sizeof(t_specifier))) == NULL)
		return (NULL);
	tmp->flag = flag;
	tmp->option = option;
	tmp->next = NULL;
	return (tmp);
}

t_specifier		*spec_lst_push(t_specifier **begin_list, char option, char *flag)
{
	t_specifier	*tmp;
	t_specifier	*tmp2;

	if (begin_list == NULL || (tmp = spec_lst_new(option, flag)) == NULL)
		return (NULL);
	if (*begin_list == NULL)
		*begin_list = tmp;
	else
	{
		tmp2 = *begin_list;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (tmp);
}

void		spec_lst_clear(t_specifier *lst)
{
	t_specifier	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->flag != NULL)
			free(tmp->flag);
		free(tmp);
	}
}
