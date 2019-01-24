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
#include "commands.h"
#include "constants.h"
#include "libft.h"

const t_builtin g_builtins[BUILTINS_AMOUNT] = {
	{"exit", &b_exit},
	{"cd", &b_cd},
	{"env", &b_env}
};

int		exec_builtin(char *command, char **args, t_shell *shell)
{
	unsigned int i;

	i = 0;
	while (i < BUILTINS_AMOUNT)
	{
		if (ft_strcmp(command, g_builtins[i].command) == 0)
		{
			g_builtins[i].func(shell, args);
			return (i);
		}
		++i;
	}
	return (0);
}
