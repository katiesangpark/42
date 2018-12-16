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
#include "file_list.h"
#include "libft.h"
#include "args.h"
#include "printing_utils.h"
#include "conditions.h"

void	print_files_inline(t_files *files)
{
	int	maxlen;

	maxlen = get_files_maxlen(files);
	while (files != NULL)
	{
		print_file_with_pad(files, files->next != NULL ? maxlen : 0);
		ft_putchar(files->next != NULL ? ' ' : '\n');
		files = files->next;
	}
}

void	print_folder_inline(t_args *args, t_folder *folders, int children)
{
	int		lst_size;

	lst_size = folder_lst_size(folders);
	while (folders != NULL)
	{
		if (is_dir(folders->fullpath) || 1)
		{
			if (lst_size > 1)
				ft_printf("%s:\n", folders->fullpath);
			print_files_inline(folders->files);
			if (args->flags & FLAG_RECURSIVE)
				print_folder_inline(args, folders->subfolders, 1);
			if (folders->next != NULL || children)
				ft_putchar('\n');
		}
		folders = folders->next;
	}
}

void	print_folder(t_args *args, t_folder *folders)
{
	print_folder_inline(args, folders, 0);
}
