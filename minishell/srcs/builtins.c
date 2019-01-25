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
#include "utils.h"

const t_builtin g_builtins[BUILTINS_AMOUNT] = {
	{"alias", &b_alias},
	{"alias-list", &b_alias_list},
	{"cd", &b_cd},
	{"doc", &b_doc},
	{"documentation", &b_doc},
	{"echo", &b_echo},
	{"env", &b_env},
	{"export", &b_export},
	{"exit", &b_exit},
	{"help", &b_help},
	{"history", &b_history},
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
	return (-1);
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
	ft_free_tab(args);
	free_env(shell->env);
	free_env(shell->alias);
	free(shell->buf);
	(void)args;
	exit(0);
}

void	b_cd(t_shell *shell, char **args)
{
	char *tmp;

	if (args[1] == NULL && !(tmp = get_env_var("HOME", shell->env)))
		ft_putstr_fd(SHELL_NAME": error: HOME variable not set\n", 2);
	else if (args[1] != NULL)
		tmp = args[1];
	if (!is_dir(tmp))
		ft_printf_fd(2, SHELL_NAME": error: \"%s\" not available or not a "
					"dir.\n", tmp);
	else
	{
		shell->pwd = tmp;
		chdir(tmp);
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
