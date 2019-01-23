/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:27:50 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:27:50 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtins.h"
#include "constants.h"
#include "libft.h"
#include <stdlib.h>

void	b_exit(char **args)
{
	(void)args;
	exit(0);
}

const s_builtin g_builtins[BUILTINS_AMOUNT] = {
	{"exit", &b_exit}
};

int		exec_builtin(char *command, char **args)
{
	unsigned int i;

	i = 0;
	while (i < BUILTINS_AMOUNT)
	{
		if (ft_strcmp(command, g_builtins[i].command) == 0)
		{
			g_builtins[i].func(args);
			return (i);
		}
		i++;
	}
	return (0);
}
