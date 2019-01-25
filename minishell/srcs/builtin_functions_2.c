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
	if (args[1][i + 1] != '\0')
		set_env_var(args[1], args[1] + i + 1, shell);
	else
		remove_env_var(args[1], shell->env);
}

void	b_doc(t_shell *shell, char **args)
{
	(void)shell;
	(void)args;
	ft_putendl(SHELL_NAME" "SHELL_VERSION" Documentation:\n\nCommand Li"
		"st:\nalias NAME; alias NAME=VALUE\nalias-list\ncd; cd DIRECTORY"
		"\ndoc\ndocumentation\necho TEXT\nenv\nexport; export NAME;expo"
		"rt NAME=VALUE\nexit\nhelp\nhistory; history -c\nlog [on/off/-c]"
		"\nsetenv NAME VAL"
		"UE\nunsetenv NAME");
}

void	b_log(t_shell *shell, char **args)
{
	int		fd;

	if (ft_strcmp(ft_strtolower(args[1]), "on") == 0)
	{
		shell->log = 1;
		log_input(shell);
	}
	else if (ft_strcmp(ft_strtolower(args[1]), "off") == 0)
		shell->log = 0;
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
