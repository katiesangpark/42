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

#include <sys/stat.h>
#include "libft.h"

int		exists(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (S_ISREG(f_stat.st_mode));
}

char	*get_env_var(char *name, char **env)
{
	unsigned int tmp;

	while (*env)
	{
		tmp = ft_strlcmp(*env, name);
		if (tmp != 0 && (*env)[tmp] == '=')
			return (*env + tmp + 1);
		++env;
	}
	return (0);
}
