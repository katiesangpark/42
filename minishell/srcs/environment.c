/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 00:34:48 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/24 00:34:48 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

char	**copy_env(char **env)
{
	int				i;
	char			**output;

	i = 0;
	while (env[i++])
		;
	if ((output = ft_memalloc(sizeof(char**) * i)) == NULL)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if ((output[i] = ft_strdup(env[i])) == NULL)
		{
			while (--i >= 0)
				free(output[i]);
			return (NULL);
		}
		++i;
	}
	output[i] = NULL;
	return (output);
}

void	free_env(char **env)
{
	unsigned int	i;

	if (env == 0)
		return ;
	i = 0;
	while (env[i])
	{
		ft_strdel(&(env[i]));
		++i;
	}
	free(env);
}

void	set_env_var(char *name, char *value, char **env)
{
	unsigned int tmp;

	while (*env)
	{
		tmp = ft_strlcmp(*env, name);
		if (tmp != 0 && (*env)[tmp] == '=')
		{
			ft_memdel((void**)env);
			*env = value;
			return ;
		}
		++env;
	}
}
