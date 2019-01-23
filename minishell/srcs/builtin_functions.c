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

void	b_exit(t_shell *shell, char **args)
{
	(void)shell;
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
