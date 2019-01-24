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
#include <stdlib.h>
#include "commands.h"
#include "constants.h"
#include "libft.h"

const t_builtin g_builtins[BUILTINS_AMOUNT] = {
	{"help", &b_help},
	{"cd", &b_cd},
	{"env", &b_env},
	{"echo", &b_echo},
	{"exit", &b_exit},
	{"setenv", &b_setenv},
	{"unsetenv", &b_unsetenv}
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

void	b_echo(t_shell *shell, char **args)
{
	(void)shell;
	while (*(++args))
	{
		ft_putstr(*args);
		if (*(args + 1))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

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

void	b_help(t_shell *shell, char **args)
{
	unsigned int	i;

	(void)shell;
	(void)args;
	i = 0;
	ft_putstr("--- "SHELL_NAME" help: ---\n");
	while (i < BUILTINS_AMOUNT)
	{
		ft_putendl(g_builtins[i].command);
		++i;
	}
}
