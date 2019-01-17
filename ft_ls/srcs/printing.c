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
#include "utils.h"
#include "get_info.h"

int		remove_nonfiles_folders(t_folder **folders)
{
	t_folder	*curr;
	t_folder	*prev;
	t_folder	*tmp;
	int			found;

	curr = *folders;
	prev = 0;
	found = 0;
	while (curr != 0)
	{
		if (!curr->is_dir && ++found)
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
	return (found);
}

void	print_invalid_folders(t_args *args, t_folder **folders)
{
	t_folder	*curr;
	t_folder	*prev;

	curr = *folders;
	prev = 0;
	while (curr != 0)
	{
		if (!exists(curr->fullpath))
		{
			ft_printf("ft_ls: %s: No such file or directory\n", curr->name);
			curr->exists = 0;
		}
		else if (is_dir(curr->fullpath))
			curr->is_dir = 1;
		else
			get_folders_info(args, curr);
		prev = curr;
		curr = curr->next;
	}
}

void	print_folder(t_args *args, t_folder *folders)
{
	if (!folders->exists)
		return ;
	if (args->flags & FLAG_LIST)
		print_folder_list(args, folders);
	else
		print_folder_inline(args, folders);
}
