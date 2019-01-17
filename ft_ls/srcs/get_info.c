/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:15:16 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:15:17 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_info.h"
#include "get_info_2.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void	get_list_info(t_files *files, struct stat *f_stat, struct stat *l_stat)
{
	struct passwd	*pwuid;
	struct group	*grgid;

	files->nlinks = f_stat->st_nlink;
	if (files->is_link)
		get_symlink_target(files);
	ft_putstr(files->name);
	build_permission_string(files->permission,
		files->is_link ? l_stat->st_mode : f_stat->st_mode);
	files->filesize = f_stat->st_size;
	if ((pwuid = getpwuid(f_stat->st_uid)) == 0)
		pwuid = getpwuid(l_stat->st_uid);
	files->owner = ft_strdup(pwuid == 0 ? "ERROR_NO_UID" : pwuid->pw_name);
	if ((grgid = getgrgid(f_stat->st_gid)) == 0)
		grgid = getgrgid(l_stat->st_gid);
	files->group = ft_strdup(grgid == 0 ? "ERROR_NO_GID" : grgid->gr_name);
}

void	get_files_info(t_args *args, t_folder *folder, t_files *files)
{
	struct stat	f_stat;
	struct stat	l_stat;

	if (files == 0)
		return ;
	lstat(files->fullpath, &f_stat);
	stat(files->fullpath, &l_stat);
	files->is_link = S_ISLNK(f_stat.st_mode);
	files->is_dir = S_ISDIR(f_stat.st_mode);
	files->is_exec = (f_stat.st_mode & (S_IXUSR | S_IXOTH | S_IXGRP)) != 0;
	files->access_time = f_stat.st_mtime;
	if (args->flags & FLAG_LIST)
	{
		folder->total += files->is_link ? l_stat.st_blocks : f_stat.st_blocks;
		get_list_info(files, &f_stat, &l_stat);
	}
	get_files_info(args, folder, files->next);
}

void	get_folders_info(t_args *args, t_folder *folders)
{
	struct stat	f_stat;
	struct stat	l_stat;

	if (folders == 0 || folders->exists == 0)
		return ;
	lstat(folders->fullpath, &f_stat);
	stat(folders->fullpath, &l_stat);
	folders->is_link = S_ISLNK(f_stat.st_mode);
	folders->is_dir = S_ISDIR(f_stat.st_mode);
	folders->access_time = f_stat.st_mtime;
	if (args->flags & FLAG_LIST)
		get_list_info((t_files*)folders, &f_stat, &l_stat);
	get_files_info(args, folders, folders->files);
}
