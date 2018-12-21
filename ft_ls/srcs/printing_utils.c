/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:46:10 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 10:46:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_list.h"
#include "conditions.h"
#include <unistd.h>

void	print_colors(t_files *files)
{
	if (files->is_link)
		ft_printf("{0a}");
	else if (files->is_dir)
		ft_printf("{0e}");
	else if (files->is_exec)
		ft_printf("{01}");
}

int		get_files_maxlen(t_files *files)
{
	int	maxlen;
	int	tmp;

	maxlen = 0;
	while (files != NULL)
	{
		tmp = ft_strlen(files->name);
		if (tmp > maxlen)
			maxlen = tmp;
		files = files->next;
	}
	return (maxlen);
}

int		get_folderfiles_maxlen(t_folder *files)
{
	int	maxlen;
	int	tmp;

	maxlen = 0;
	while (files != NULL)
	{
		if (files->is_dir)
		{
			tmp = ft_strlen(files->name);
			if (tmp > maxlen)
				maxlen = tmp;
		}
		files = files->next;
	}
	return (maxlen);
}

void	print_file_with_pad(t_files *file, int maxlen)
{
	int		len;

	len = ft_strlen(file->name);
	write(1, file->name, len);
	ft_print_char(' ', maxlen - len);
}
