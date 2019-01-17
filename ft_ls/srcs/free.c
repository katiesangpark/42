/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:06:29 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 16:06:30 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <stdlib.h>

void	free_files(t_files **file)
{
	t_files	*curr;
	t_files *next;

	curr = *file;
	while (curr != NULL)
	{
		free(curr->name);
		free(curr->prefix);
		free(curr->fullpath);
		free(curr->symlink_path);
		free(curr->owner);
		free(curr->group);
		next = curr->next;
		free(curr);
		curr = next;
	}
	*file = 0;
}

void	free_single_folder(t_folder **folder)
{
	free_files(&((*folder)->files));
	ft_strdel(&(*folder)->name);
	ft_strdel(&(*folder)->prefix);
	ft_strdel(&(*folder)->fullpath);
	ft_strdel(&(*folder)->symlink_path);
	ft_strdel(&(*folder)->owner);
	ft_strdel(&(*folder)->group);
	ft_memdel((void**)folder);
}
