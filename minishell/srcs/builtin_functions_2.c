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
		"rt NAME=VALUE\nexit\nhelp\nsetenv NAME VALUE\nunsetenv NAME");
}
