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

t_folder	*get_last_folderfile(t_folder *files)
{
	t_folder	*end;

	end = 0;
	while (files != 0)
	{
		if (!files->is_dir)
			end = files;
		files = files->next;
	}
	return (end);
}

void		print_owner_with_pad(t_files *files, int reset)
{
	static size_t	len = 0;

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
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

	if (reset != 0)
	{
		len = 0;
		while (files != 0)
		{
			if (unbrlen(files->filesize) > len)
				len = unbrlen(files->filesize);
			files = files->next;
		}
	}
	else if (files != 0)
	{
		ft_print_char(' ', len - unbrlen(files->filesize));
		ft_putnbr(files->filesize);
		ft_putchar(' ');
	}
}
