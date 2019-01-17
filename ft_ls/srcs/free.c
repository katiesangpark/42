/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:06:29 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 16:06:30 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"

void	free_file(t_files **file)
{
	if (file == NULL || *file == NULL)
		return ;
	free_file(&(*file)->next);
	ft_strdel(&(*file)->name);
	ft_strdel(&(*file)->prefix);
	ft_strdel(&(*file)->fullpath);
	ft_strdel(&(*file)->symlink_path);
	ft_strdel(&(*file)->owner);
	ft_strdel(&(*file)->group);
	ft_memdel((void**)file);
}

void	free_single_folder(t_folder **folder)
{
	free_file(&((*folder)->files));
	ft_strdel(&(*folder)->name);
	ft_strdel(&(*folder)->prefix);
	ft_strdel(&(*folder)->fullpath);
	ft_strdel(&(*folder)->symlink_path);
	ft_strdel(&(*folder)->owner);
	ft_strdel(&(*folder)->group);
	ft_memdel((void**)folder);
}

void	free_folder(t_folder **folder)
{
	if (folder == NULL || *folder == NULL)
		return ;
	free_folder(&(*folder)->subfolders);
	free_folder(&(*folder)->next);
	free_single_folder(folder);
	ft_memdel((void**)folder);
}

void	free_args(t_args **args)
{
	//free_folder(&(*args)->search_folder);
	ft_memdel((void*)args);
}
