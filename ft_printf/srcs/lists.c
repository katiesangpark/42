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

t_specifier		*spec_lst_new(char option, char *flag, int idx)
{
	t_specifier	*tmp;

	if ((tmp = (t_specifier*)malloc(sizeof(t_specifier))) == NULL)
		return (NULL);
	tmp->flag = flag;
	tmp->option = option;
	tmp->idx = idx;
	tmp->next = NULL;
	tmp->len = 0;
	return (tmp);
}

void			spec_lst_push(t_specifier **begin_list, t_specifier *spec)
{
	t_specifier *tmp;

	if (begin_list == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = spec;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = spec;
	}
}

void			spec_lst_clear(t_specifier *lst)
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
