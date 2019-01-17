/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_access_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 06:15:31 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/05 06:15:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_access_time.h"
#include "libft.h"

void	sort_access_time_files(t_files **files)
{
	t_files	*curr;
	t_files *next;
	t_files *prev;

	if (files == 0 || (curr = *files) == 0)
		return ;
	prev = 0;
	while ((next = curr->next) != 0)
	{
		if (curr->access_time < next->access_time || (curr->access_time
			== next->access_time && ft_strcmp(curr->name, next->name) > 0))
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

void	sort_access_time(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*next;
	t_folder	*prev;

	if (folders == 0 || (curr = *folders) == 0)
		return ;
	prev = 0;
	while ((next = curr->next) != 0)
	{
		if (curr->access_time < next->access_time || (curr->access_time
			== next->access_time && ft_strcmp(curr->name, next->name) > 0))
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
