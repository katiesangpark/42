/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:12:15 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 23:12:15 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"
#include "arguments.h"
#include "commands.h"
#include "constants.h"

void	b_export(t_shell *shell, char **args)
{
	int		i;
	char	*tmp;

	if (args[1] == 0)
	{
		b_env(shell, args);
		return ;
	}
	i = ft_cfind(args[1], '=');
	if (i == -1)
	{
		tmp = get_env_var(args[1], shell->env);
		if (tmp != NULL)
			ft_printf("%s=%s\n", args[1], tmp);
		return ;
	}
	if (i == 0)
		return ;
	args[1][i] = '\0';
	ft_putnbr(charset_unmatch(args[1] + i + 1, "-\\();><\"'"));
	if (args[1][i + 1] != '\0')
		set_env_var(args[1], args[1] + i + 1, shell);
	else
		remove_env_var(args[1], shell->env);
}

void	b_doc(t_shell *shell, char **args)
{
	(void)shell;
	(void)args;
	ft_putendl("--- "SHELL_NAME" "SHELL_VERSION" Documentation: ---\n"
		"Command List:\n  alias (NAME)(=VALUE)\n  alias-list\n  "
		"cd (DIRECTORY)\n  doc(umentation)\n  echo (TEXT)\n  env\n  "
		"export (NAME)(=VALUE)\n  exit\n  help\n  history (-c)\n  log"
		"[on/off/-c]\n  setenv [NAME] [VALUE]\n  unsetenv [NAME]");
}

void	b_log(t_shell *shell, char **args)
{
	int		fd;

	if (ft_strcmp(ft_strtolower(args[1]), "on") == 0)
	{
		shell->no_log = 0;
		log_input(shell);
	}
	else if (ft_strcmp(ft_strtolower(args[1]), "off") == 0)
		shell->no_log = 1;
	else if (ft_strcmp(args[1], "-c") == 0 || ft_strcmp(args[1], "clear") == 0)
	{
		if ((fd = open(LOG_FILE, O_RDWR | O_TRUNC | O_CREAT, 448)) < 0)
			ft_putstr_fd(SHELL_NAME": error: could not clear log file "LOG_FILE
		".\n", 2);
		else
			close(fd);
	}
	else
		ft_putstr_fd("Usage: log [on/off/-c/clear]\n", 2);
}

void	b_history(t_shell *shell, char **args)
{
	int		fd;
	int		ret;
	char	buf[256];

	(void)shell;
	if (args[1] == NULL)
	{
		if ((fd = open(LOG_FILE, O_RDONLY)) < 0)
			ft_putstr_fd(SHELL_NAME": error: could not read log file "LOG_FILE
		".\n", 2);
		else
			while ((ret = read(fd, buf, 256)) > 0)
				write(1, buf, ret);
		close(fd);
	}
	else if (ft_strcmp(args[1], "-c") == 0 || ft_strcmp(args[1], "clear") == 0)
	{
		if ((fd = open(LOG_FILE, O_RDWR | O_TRUNC | O_CREAT, 448)) < 0)
			ft_putstr_fd(SHELL_NAME": error: could not clear log file "LOG_FILE
		".\n", 2);
		else
			close(fd);
	}
	else
		ft_putstr_fd("Usage: history [-clear/clear]\n", 2);
}

void	b_args(t_shell *shell, char **args)
{
	if (args[1] == NULL)
	{
		ft_putendl("Usage: args --no-log --color --show-dir --show-dir-first");
		return ;
	}
	if (ft_strcmp(args[1], "reset") == 0)
	{
		shell->no_log = 0;
		shell->no_shrc = 0;
		shell->color = 0;
		shell->showdir = 0;
		return ;
	}
	shell->show_shlvl = get_arg("--shlvl", 0, args)
			|| get_arg_letter('l', 0, args);
	shell->no_log = get_arg("--no-log", 0, args)
			|| get_arg_letter('s', 0, args);
	shell->no_shrc = get_arg("--no-shrc", 0, args)
			|| get_arg_letter('d', 0, args);
	shell->color = get_arg("--color", 0, args)
			|| get_arg_letter('G', 0, args);
	shell->showdir = (get_arg("--show-dir", 0, args)
			|| get_arg_letter('i', 0, args));
	if (get_arg("--show-dir-first", 0, args) || get_arg_letter('I', 0, args))
		shell->showdir = 2;
}
