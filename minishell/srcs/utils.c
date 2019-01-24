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

char	*build_string_with_num(char *str, int n)
{
	unsigned int	i;
	unsigned int	len;
	char			*output;

	len = nbrlen(n);
	if ((output = ft_strnew(ft_strlen(str) + len)) == NULL)
		return (NULL);
	ft_strcpy(output, str);
	i = 0;
	while (output[i] != '\0')
		++i;
	i += len;
	output[i] = '\0';
	while (n != 0)
	{
		output[--i] = '0' + n % 10;
		n /= 10;
	}
	return (output);
}

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
	return (S_ISREG(f_stat.st_mode));
}

int		is_dir(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) != 0)
		return (0);
	return (S_ISDIR(f_stat.st_mode));
}
