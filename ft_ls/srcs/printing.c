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
#include "printing_utils.h"

void	print_files_inline(t_files *files)
{
	int	maxlen;

	maxlen = get_files_maxlen(files);
	while (files != NULL)
	{
		print_file_with_pad(files, maxlen);
		ft_putchar(files->next != NULL ? ' ' : '\n');
		files = files->next;
	}
}

void	print_folder(t_folder *folders)
{
	int		lst_size;

	lst_size = folder_lst_size(folders);

	while (folders != NULL)
	{
		if (lst_size > 1)
			ft_printf("%s:\n", folders->name);
		print_files_inline(folders->files);
		folders = folders->next;
		if (folders != NULL)
			ft_putchar('\n');
	}
}
