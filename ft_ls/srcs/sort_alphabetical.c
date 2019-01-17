/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alphabetical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:21 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/19 17:23:21 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_alphabetical.h"
#include "libft.h"

void	sort_alphabetical_files(t_files **files)
{
	t_files		*curr;
	t_files		*next;
	t_files		*prev;

	if (files == 0 || (curr = *files) == 0)
		return ;
	prev = 0;
	while ((next = curr->next) != 0)
	{
		if (ft_strcmp(curr->name, next->name) > 0)
		{
			curr->next = next->next;
			next->next = curr;
			if (prev == 0)
				*files = next;
			else
				prev->next = next;
			curr = *files;
			prev = 0;
			continue ;
		}
		prev = curr;
		curr = next;
	}
}

void	sort_alphabetical(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*next;
	t_folder	*prev;

	if (folders == 0 || (curr = *folders) == 0)
		return ;
	prev = 0;
	while ((next = curr->next) != 0)
	{
		if (ft_strcmp(curr->name, next->name) > 0)
		{
			curr->next = next->next;
			next->next = curr;
			if (prev == 0)
				*folders = next;
			else
				prev->next = next;
			curr = *folders;
			prev = 0;
			continue ;
		}
		prev = curr;
		curr = next;
	}
}
