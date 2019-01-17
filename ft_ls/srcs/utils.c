/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 04:13:43 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 04:13:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <sys/stat.h>

char	*build_prefix(char *prev_prefix, char *curr_folder)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(prev_prefix) + ft_strlen(curr_folder) + 2);
	if (tmp == NULL)
		return (NULL);
	ft_strcat(tmp, prev_prefix);
	ft_strcat(tmp, curr_folder);
	if (curr_folder[ft_strlen(curr_folder) - 1] != '/')
		ft_strcat(tmp, "/");
	return (tmp);
}

int		exists(char *path)
{
	struct stat	f_stat;
	struct stat	l_stat;

	return (lstat(path, &f_stat) + stat(path, &l_stat) == 0);
}

int		is_dir(char *path)
{
	struct stat	f_stat;
	struct stat	l_stat;

	stat(path, &f_stat);
	lstat(path, &l_stat);
	return (S_ISDIR(f_stat.st_mode) || S_ISDIR(l_stat.st_mode));
}
