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

void	b_setenv(t_shell *shell, char **args)
{
	(void)shell;
	(void)args;
}

void	b_unsetenv(t_shell *shell, char **args)
{
	(void)shell;
	(void)args;
}
