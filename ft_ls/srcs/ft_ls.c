/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:17:14 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 22:17:15 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_struct.h"
#include "args.h"
#include "libft.h"
#include "ft_ls.h"
#include "utils.h"
#include "conditions.h"
#include "printing.h"
#include "get_info.h"
#include "get_info_2.h"
#include "free.h"
#include "sort.h"
#include <dirent.h>
#include <stdlib.h>

void	list_files(t_args *args, t_folder *curr)
{
	DIR				*d;
	struct dirent	*f;
	t_files			*file;
	t_folder		*subfolder;
	t_folder		*next;

	d = (curr == NULL || !curr->exists) ? (NULL) : (opendir(curr->fullpath));
	while (d && (f = readdir(d)) != NULL)
	{
		if (is_hidden(f->d_name, args))
			continue ;
		file = file_lst_new(f->d_name, build_prefix(curr->prefix, curr->name));
		files_lst_push(&curr->files, file);
		if (!file || f->d_type != DT_DIR || is_dot(file->name))
			continue ;
		subfolder = folder_lst_new(f->d_name, ft_strdup(file->prefix));
		folder_lst_push(&curr->subfolders, subfolder);
	}
	if (d)
	{
		sort_files(args, &curr->files);
		get_folders_info(args, curr);
		print_folder(args, curr);
		if (args->flags & FLAG_RECURSIVE)
		{
			sort_folders(args, &curr->subfolders);
			list_files(args, curr->subfolders);
		}
		closedir(d);
	}
	if (curr)
	{
		next = curr->next;
		free_single_folder(&curr);
		list_files(args, next);
	}
}

void	print_invalid_folders(t_folder **folders)
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
		prev = curr;
		curr = curr->next;
	}
}

int		main(int ac, char **av)
{
	t_args		*args;
	int			err;

	if ((args = new_args()) == NULL)
		return (0);
	if ((err = validate_arguments(args, ac, av)) == ERR_NO_ERR)
	{
		sort_folders(args, &args->search_folder);
		print_invalid_folders(&args->search_folder);
		list_files(args, args->search_folder);
	}
	else if (err == ERR_INVALID_ARG)
	{
		free_single_folder(&args->search_folder);
		ft_printf("usage: ft_ls [-%s] [file ...]\n", FLAGS);
	}
	free(args);
	return (0);
}
