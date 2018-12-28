/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:17:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 16:17:27 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "file_list.h"
#include "list_utils.h"
#include "libft.h"
#include "args.h"
#include "free.h"
#include "printing_utils.h"
#include "conditions.h"

void	print_files_inline(t_files *files)
{
	int	maxlen;

	maxlen = get_files_maxlen(files);
	while (files != NULL)
	{
		print_colors(files);
		print_file_with_pad(files, files->next != NULL ? maxlen : 0);
		ft_printf("{RESET}");
		ft_putchar(files->next != NULL ? ' ' : '\n');
		files = files->next;
	}
}

void	print_folderfiles_inline(t_folder *files)
{
	int			maxlen;
	int			nonfolders;
	int			regfolders;
	t_folder	*end;

	nonfolders = 0;
	regfolders = 0;
	maxlen = get_folderfiles_maxlen(files);
	end = get_last_folderfile(files);
	while (files != NULL)
	{
		if (!files->is_dir && files->exists)
		{
			print_colors((t_files*)files);
			print_file_with_pad((t_files*)files, files != end ? maxlen : 0);
			ft_printf("{RESET}");
			ft_putchar(files != end ? ' ' : '\n');
			nonfolders = 1;
		}
		else if (files->exists)
			regfolders = 1;
		files = files->next;
	}
	if (nonfolders && regfolders)
		ft_putchar('\n');
}

void	print_folder_inline(t_args *args, t_folder *folders)
{
	while (folders != NULL)
	{
		if ((folders->next != NULL || folders != args->search_folder))
			ft_printf("%s:\n", folders->fullpath);
		if (folders->is_readable == 0)
			ft_printf("ft_ls: %s: Permission denied.\n", folders->name);
		print_files_inline(folders->files);
		if ((args->flags & FLAG_RECURSIVE) && folders->subfolders != 0)
		{
			ft_putchar('\n');
			print_folder_inline(args, folders->subfolders);
		}
		if (folders->next != NULL)
			ft_putchar('\n');
		folders = folders->next;
	}
}