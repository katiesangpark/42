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

#include <stdlib.h>
#include "libft.h"
#include "utils.h"

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

char	**copy_env(char **env, char *newelem)
{
	int				len;
	int				i;
	char			**output;

	i = -1;
	len = (newelem != NULL);
	while (env[++i])
		if (env[i][0] != '\0')
			len++;
	if ((output = ft_memalloc(sizeof(char**) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (env[i])
	{
		if (env[i][0] != '\0'
			&& (output[len++] = ft_strdup(env[i])) == NULL)
			return (reverse_free_tab(output, len));
		++i;
	}
	if (newelem != 0)
		output[len++] = newelem;
	output[len] = NULL;
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

void	remove_env_var(char *name, char **env)
{
	unsigned int tmp;

	while (*env)
	{
		tmp = ft_strlcmp(*env, name);
		if (tmp != 0 && (*env)[tmp] == '=')
		{
			*env[0] = '\0';
			return ;
		}
		++env;
	}
}

void	set_env_var(char *name, char *value, t_shell *shell)
{
	unsigned int	tmp;
	unsigned int	i;
	char			**tmpenv;

	i = 0;
	while (shell->env[i])
	{
		tmp = ft_strlcmp(shell->env[i], name);
		if (tmp != 0 && (shell->env[i])[tmp] == '=')
		{
			ft_strdel(&(shell->env[i]));
			shell->env[i] = concat_env_string(name, value);
			return ;
		}
		++i;
	}
	tmpenv = shell->env;
	shell->env = copy_env(tmpenv, concat_env_string(name, value));
	free_env(tmpenv);
}
