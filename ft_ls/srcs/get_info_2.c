/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:15:16 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:15:17 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_info_2.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>

void	build_permission_string(char *str, int st_mode, int is_link)
{
	ft_strcpy(str, "----------  ");
	if (S_ISDIR(st_mode))
		str[0] = 'd';
	if (is_link)
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

void	get_symlink_target(t_files *file)
{
	char	buf[257];
	char	*out;
	int		read;

	if (!file->is_link)
		return ;
	read = readlink(file->fullpath, buf, 256);
	if (read <= 0 || read >= 257)
		return ;
	out = ft_memdup(buf, read + 1);
	if (out != 0)
	{
		out[read] = '\0';
		file->symlink_path = out;
	}
}
