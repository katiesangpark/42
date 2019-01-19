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

char	get_last_char(char *str)
{
	while (str[0] && str[1])
		str++;
	return (*str);
}

int		is_dir(t_args *args, char *path)
{
	struct stat	f_stat;

	if (get_last_char(path) == '/' || (args->flags & FLAG_LIST) == 0)
		stat(path, &f_stat);
	else
		lstat(path, &f_stat);
	return (S_ISDIR(f_stat.st_mode));
}
