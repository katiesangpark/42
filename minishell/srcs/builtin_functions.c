/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:12:15 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:12:15 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "commands.h"
#include "utils.h"

void	b_exit(t_shell *shell, char **args)
{
	free_env(shell->env);
	free(shell->buf);
	(void)args;
	exit(0);
}

void	b_cd(t_shell *shell, char **args)
{
	if (args[1] == NULL)
	{
		shell->pwd = "/";
		chdir("/");
	}
	else
	{
		shell->pwd = args[1];
		chdir(args[1]);
	}
}

void	b_env(t_shell *shell, char **args)
{
	unsigned int i;

	(void)args;
	i = 0;
	while (shell->env[i])
	{
		ft_putendl(shell->env[i]);
		++i;
	}
}
