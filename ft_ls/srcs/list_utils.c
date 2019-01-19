/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:02:04 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:02:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_list.h"
#include "conditions.h"
#include "libft.h"

void		print_owner_with_pad(t_files *files, int reset)
{
	static size_t	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (ft_strlen(files->owner) > len)
					len = ft_strlen(files->owner);
			}
			else if (reset == 2 && files->folderfile)
				if (ft_strlen(files->owner) > len)
					len = ft_strlen(files->owner);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_putstr(files->owner);
		ft_print_char(' ', len - ft_strlen(files->owner) + 2);
	}
}

void		print_group_with_pad(t_files *files, int reset)
{
	static size_t	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (ft_strlen(files->group) > len)
					len = ft_strlen(files->group);
			}
			else if (reset == 2 && files->folderfile)
				if (ft_strlen(files->group) > len)
					len = ft_strlen(files->group);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_putstr(files->group);
		ft_print_char(' ', len - ft_strlen(files->group) + 2);
	}
}

void		print_links_with_pad(t_files *files, int reset)
{
	static int	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (reset == 1 && !files->folderfile)
			{
				if (nbrlen(files->nlinks) > len)
					len = nbrlen(files->nlinks);
			}
			else if (reset == 2 && files->folderfile)
				if (nbrlen(files->nlinks) > len)
					len = nbrlen(files->nlinks);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_print_char(' ', len - nbrlen(files->nlinks));
		ft_putnbr(files->nlinks);
		ft_putchar(' ');
	}
}

void		print_size_with_pad(t_files *files, int reset)
{
	static int	len = 0;
	int			tmplen;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			tmplen = unbrlen(files->major);
			if (files->filetype == 'b' || files->filetype == 'c')
				tmplen = unbrlen(files->major) + unbrlen(files->minor) + 2;
			if ((reset == 1 && !files->folderfile)
				|| (reset == 2 && files->folderfile))
			{
				if (tmplen > len)
					len = tmplen;
			}
			files = files->next;
		}
	}
	else if (files != 0)
	{
		if (files->filetype == 'b' || files->filetype == 'c')
		{
			ft_print_char(' ', len - unbrlen(files->major) - unbrlen(files->minor) - 2);
			ft_printf("%d, %d", files->major, files->minor);
		}
		else
		{
			ft_print_char(' ', len - unbrlen(files->filesize));
			ft_putnbr(files->filesize);
		}
		ft_putchar(' ');
	}
}
