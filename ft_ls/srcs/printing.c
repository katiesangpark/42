/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:25:53 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 10:25:54 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "args.h"
#include "file_list.h"
#include "print_inline.h"
#include "print_list.h"
#include "libft.h"
#include "free.h"

void	remove_nonfiles_folders(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*prev;
	t_folder	*tmp;

	curr = *folders;
	prev = 0;
	while (curr != 0)
	{
		if (!curr->is_dir)
		{
			if (prev != 0)
				prev->next = curr->next;
			else
				*folders = curr->next;
			tmp = curr;
			curr = curr->next;
			free_single_folder(&tmp);
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	remove_unexisting_folders(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*prev;
	t_folder	*tmp;

	curr = *folders;
	prev = 0;
	while (curr != 0)
	{
		if (!curr->exists)
		{
			if (prev != 0)
				prev->next = curr->next;
			else
				*folders = curr->next;
			tmp = curr;
			curr = curr->next;
			free_single_folder(&tmp);
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	print_folder(t_args *args, t_folder *folders)
{
	remove_unexisting_folders(&folders);
	if (args->flags & FLAG_LIST)
	{
		print_folderfiles_list(folders);
		remove_nonfiles_folders(&folders);
		args->search_folder = folders;
		print_folder_list(args, folders);
	}
	else
	{
		print_folderfiles_inline(folders);
		remove_nonfiles_folders(&folders);
		args->search_folder = folders;
		print_folder_inline(args, folders);
	}
}
