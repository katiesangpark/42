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
	t_files	*curr;
	t_files *next;

	if (files == 0 || (curr = *files) == 0)
		return ;
	while ((next = curr->next) != 0)
	{
		if (ft_strcmp(curr->name, next->name) > 0)
		{
			ft_swap((void**)&curr->name, (void**)&next->name);
			ft_swap((void**)&curr->fullpath, (void**)&next->fullpath);
			ft_swap((void**)&curr->prefix, (void**)&next->prefix);
			curr = *files;
			continue ;
		}
		curr = curr->next;
	}
}

void	sort_alphabetical(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*next;
	t_folder	tmp;

	if (folders == 0 || (curr = *folders) == 0)
		return ;
	while ((next = curr->next) != 0)
	{
		if (ft_strcmp(curr->name, next->name) > 0)
		{
			ft_memcpy(&tmp, curr, 24);
			ft_memcpy(curr, next, 24);
			ft_memcpy(next, &tmp, 24);
			ft_swap((void**)&curr->files, (void**)&next->files);
			ft_swap((void**)&curr->subfolders, (void**)&next->subfolders);
			curr = *folders;
			continue ;
		}
		curr = curr->next;
	}
}
