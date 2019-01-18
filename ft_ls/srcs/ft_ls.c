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

void	list_files2(DIR *d, t_args *args, t_folder *curr)
{
	if (d)
	{
		get_folders_info(args, curr);
		sort_files(args, &curr->files);
		print_folder(args, curr);
		if (args->flags & FLAG_RECURSIVE && curr->subfolders)
		{
			sort_folders(args, &curr->subfolders);
			list_files(args, curr->subfolders);
			if (curr->next != NULL)
				ft_putchar('\n');
		}
		closedir(d);
	}
	else if (curr->exists)
	{
		ft_printf("%s:\n", curr->fullpath);
		ft_printf_fd(2, "ft_ls: %s: Permission denied\n", curr->name);
		if (curr->next != NULL)
			ft_putchar('\n');
	}
	free_single_folder(&curr);
}

void	add_dots(int dotdot, t_folder *curr)
{
	if (!dotdot)
		return ;
	files_lst_push(&curr->files, file_lst_new(".", build_prefix(curr->prefix,
					curr->name)));
	files_lst_push(&curr->files, file_lst_new("..", build_prefix(curr->prefix,
		curr->name)));
}

void	list_files(t_args *args, t_folder *curr)
{
	DIR				*d;
	struct dirent	*f;
	t_files			*file;
	t_folder		*next;

	while (curr != NULL)
	{
		d = (!curr->exists) ? (NULL) : (opendir(curr->fullpath));
		add_dots((args->flags & FLAG_ALL) && !(args->flags & FLAG_UPPER_A), curr);
		while (d && (f = readdir(d)) != NULL)
		{
			if (is_hidden(f->d_name, args) || is_dot(f->d_name))
				continue ;
			file = file_lst_new(f->d_name,
				build_prefix(curr->prefix, curr->name));
			files_lst_push(&curr->files, file);
			get_files_info(args, curr, file);
			if (!file || f->d_type != DT_DIR
				|| (args->flags & FLAG_RECURSIVE) == 0)
				continue ;
			folder_lst_push(&curr->subfolders,
				folder_lst_new(f->d_name, ft_strdup(file->prefix)));
		}
		next = curr->next;
		list_files2(d, args, curr);
		curr = next;
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
		complete_arguments(args);
		sort_folders(args, &args->search_folder);
		print_invalid_folders(args, &args->search_folder);
		remove_nonfiles_folders(&args->search_folder);
		list_files(args, args->search_folder);
	}
	else if (err == ERR_INVALID_ARG)
	{
		ft_putstr("usage: ft_ls ["FLAGS"] [file ...]\n");
		if (args->search_folder)
			free_single_folder(&(args->search_folder));
	}
	free(args);
	return (0);
}
