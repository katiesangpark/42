/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:24:39 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/19 16:24:39 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_list.h"
#include "printing_utils.h"
#include "printing.h"
#include "file_list.h"
#include "list_utils.h"
#include "libft.h"
#include "args.h"
#include "free.h"
#include "conditions.h"

void	print_file_name(t_files *files)
{
	ft_putstr(files->permission);
	print_colors(files);
	ft_putstr(files->name);
	ft_printf("{RESET}");
	if (files->symlink_path != NULL)
		ft_printf(" -> %s", files->symlink_path);
	ft_putchar('\n');
}

void	print_files_list(t_files *files)
{
	while (files != 0)
	{
		print_file_name(files);
		files = files->next;
	}
}

void	print_folderfiles_list(t_folder *files)
{
	int			nonfolders;
	int			regfolders;

	nonfolders = 0;
	regfolders = 0;
	while (files != NULL)
	{
		if (!files->is_dir && files->exists)
		{
			print_file_name((t_files*)files);
			nonfolders = 1;
		}
		else if (files->exists)
			regfolders = 1;
		files = files->next;
	}
	if (nonfolders && regfolders)
		ft_putchar('\n');
}

void	print_folder_list(t_args *args, t_folder *folders)
{
	while (folders != NULL)
	{
		if (folders->files != 0)
			ft_printf("total %d\n", folders->total);
		if ((folders->next != NULL || folders != args->search_folder))
			ft_printf("%s:\n", folders->fullpath);
		if (folders->is_readable == 0)
			ft_printf("ft_ls: %s: Permission denied.\n", folders->name);
		print_files_list(folders->files);
		if ((args->flags & FLAG_RECURSIVE) && folders->subfolders != 0)
		{
			ft_putchar('\n');
			print_folder_list(args, folders->subfolders);
		}
		if (folders->next != NULL)
			ft_putchar('\n');
		folders = folders->next;
	}
}
