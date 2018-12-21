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
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>

void	build_permission_string(char *str, int st_mode)
{
	ft_strcpy(str, "----------  ");
	if (S_ISDIR(st_mode))
		str[0] = 'd';
	if (S_ISLNK(st_mode))
		str[0] = 'l';
	if (st_mode & S_IRUSR)
		str[1] = 'r';
	if (st_mode & S_IWUSR)
		str[2] = 'w';
	if (st_mode & S_IXUSR)
		str[3] = 'x';
	if (st_mode & S_IRGRP)
		str[4] = 'r';
	if (st_mode & S_IWGRP)
		str[5] = 'w';
	if (st_mode & S_IXGRP)
		str[6] = 'x';
	if (st_mode & S_IROTH)
		str[7] = 'r';
	if (st_mode & S_IWOTH)
		str[8] = 'w';
	if (st_mode & S_IXOTH)
		str[9] = 'x';
}

void	get_symlink_target(t_files *files)
{
	char	buf[257];
	char	*out;
	int		read;

	if (!files->is_link)
		return ;
	read = readlink(files->fullpath, buf, 257);
	if (read <= 0 || read >= 257)
		return ;
	out = ft_memdup(buf, read + 1);
	if (out != 0)
	{
		out[read] = '\0';
		files->symlink_path = out;
	}
}

void	get_files_info(t_args *args, t_folder *folder, t_files *files)
{
	struct stat	f_stat;
	struct stat	l_stat;

	if (files == 0)
		return ;
	if (stat(files->fullpath, &f_stat) && lstat(files->fullpath, &l_stat))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", files->name);
		files->exists = 0;
	}
	else
	{
		files->is_link = S_ISLNK(l_stat.st_mode);
		files->is_dir = S_ISDIR(f_stat.st_mode);
		files->is_exec = (f_stat.st_mode & (S_IXUSR | S_IXOTH | S_IXGRP)) != 0;
		if (args->flags & FLAG_LIST)
		{
			folder->total += f_stat.st_blocks;
			get_symlink_target(files);
			build_permission_string(files->permission,
				files->is_link ? (l_stat.st_mode) : (f_stat.st_mode));
		}
	}
	get_files_info(args, folder, files->next);
}

int		is_readable(t_files *file, struct stat *f_stat, struct stat *l_stat)
{
	(void)file;
	(void)l_stat;
	return (f_stat->st_mode & (S_IRUSR | S_IROTH | S_IRGRP));
}

void	get_folders_info(t_args *args, t_folder *folders)
{
	struct stat	f_stat;
	struct stat	l_stat;

	if (folders == 0)
		return ;
	if (lstat(folders->fullpath, &f_stat) && stat(folders->fullpath, &l_stat))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", folders->name);
		folders->exists = 0;
	}
	else
	{
		folders->is_link = S_ISLNK(f_stat.st_mode);
		folders->is_dir = S_ISDIR(f_stat.st_mode);
		folders->is_readable = is_readable((t_files*)folders, &f_stat, &l_stat);
		if (args->flags & FLAG_LIST)
		{
			get_symlink_target((t_files*)folders);
			build_permission_string(folders->permission,
				folders->is_link ? (f_stat.st_mode) : (l_stat.st_mode));
		}
	}
	get_files_info(args, folders, folders->files);
	get_folders_info(args, folders->next);
	get_folders_info(args, folders->subfolders);
}
