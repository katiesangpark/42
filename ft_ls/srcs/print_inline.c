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

void	print_files_inline(t_args *args, t_files *files)
{
	int	maxlen;

	maxlen = get_files_maxlen(files);
	while (files != NULL)
	{
		if (args->flags & FLAG_COLOR)
			print_colors(files);
		print_file_with_pad(files, files->next != NULL ? maxlen : 0);
		if (args->flags & FLAG_COLOR)
			ft_printf("{RESET}");
		ft_putchar(files->next != NULL ? ' ' : '\n');
		files = files->next;
	}
}

void	print_folder_inline(t_args *args, t_folder *folders)
{
	if (folders != args->search_folder)
		ft_printf("%s:\n", folders->fullpath);
	print_files_inline(args, folders->files);
	if ((args->flags & FLAG_RECURSIVE) && folders->subfolders != 0)
	{
		ft_putchar('\n');
		print_folder_inline(args, folders->subfolders);
	}
	if (folders->next != NULL && folders->next->exists)
		ft_putchar('\n');
}
