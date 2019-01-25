/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:20:23 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:20:24 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include <stdlib.h>
#include <sys/stat.h>

char	*concat_env_string(char *name, char *value)
{
	unsigned int	len;
	char			*output;

	len = ft_strlen(name);
	if ((output = ft_strnew(len + 1 + ft_strlen(value))) == NULL)
		return (NULL);
	ft_memcpy(output, name, len);
	output[len] = '=';
	ft_strcpy(output + len + 1, value);
	return (output);
}

int		exists(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (!S_ISDIR(f_stat.st_mode));
}

int		is_executable(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (!S_ISDIR(f_stat.st_mode) && (f_stat.st_mode & S_IXUSR));
}

int		is_dir(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (S_ISDIR(f_stat.st_mode));
}

char	*get_cwd(t_shell *shell, char *path)
{
	int	i;
	int	last;

	if (path == NULL)
		return ("");
	if (ft_strcmp(path, get_env_var("HOME", shell->env)) == 0)
		return ("~");
	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			last = i;
		++i;
	}
	return (path + last + 1);
}
