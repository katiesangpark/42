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
#include <dirent.h>

void	list_files(t_args *args, t_folder *curr)
{
	DIR				*d;
	struct dirent	*f;
	t_files			*file;
	t_folder		*subfolder;

	d = (curr == NULL) ? (NULL) : (opendir(curr->fullpath));
	if (d)
		ft_printf("%s:\n", curr->fullpath);
	while (curr && d && (f = readdir(d)) != NULL)
	{
		if (is_hidden(f->d_name, args))
			continue ;
		file = file_lst_new(f->d_name, build_prefix(curr->prefix, curr->name));
		files_lst_push(&curr->files, file);
		ft_printf("%s\n", file->fullpath);
		if (file && f->d_type != DT_DIR)
			continue ;
		subfolder = folder_lst_new(f->d_name, ft_strdup(file->prefix));
		folder_lst_push(&curr->subfolders, subfolder);
		if (is_recursive(file->name, args))
			list_files(args, subfolder);
	}
	if (curr)
		ft_putchar('\n');
	if (d)
		closedir(d);
	else if (curr && !is_file(curr->fullpath))
		ft_printf("ft_ls: %s: No such file or directory\n", curr->name);
	if (curr)
		list_files(args, curr->next);
}

int		main(int ac, char **av)
{
	t_args		*args;
	t_folder	*curr;
	int			err;

	if ((args = new_args()) == NULL)
		return (0);
	curr = NULL;
	if ((err = validate_arguments(args, ac, av)) == ERR_NO_ERR)
	{
		list_files(args, args->search_folder);
	}
	else if (err == ERR_INVALID_ARG)
		ft_printf("usage: ft_ls [-%s] [file ...]\n", FLAGS);
	free_args(&args);
	free_folder(&curr);
	return (0);
}
