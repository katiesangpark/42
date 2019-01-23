/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:49:33 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/22 15:49:33 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parsing.h"
#include "constants.h"
#include "commands.h"
#include "libft.h"
#include "shell.h"
#include "utils.h"

void	get_env_vars(t_shell *shell, char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			shell->path = *env + 5;
		else if (ft_strncmp(*env, "PWD=", 4) == 0)
			shell->pwd = *env + 4;
		++env;
	}
	shell->env = env;
}

int		main(int ac, char **av, char **env)
{
	char	**args;
	char	buf[256];
	int		offset;
	t_shell	shell;

	(void)av;
	(void)ac;
	get_env_vars(&shell, env);
	ft_putendl(shell.path);
	while (1)
	{
		write(1, PROMPT, PROMPT_LENGTH);
		offset = 0;
		read(0, buf, 1);
		while (buf[offset++] != '\n')
			read(0, buf + offset, 1);
		buf[offset - 1] = '\0';
		args = parse_input(buf);
		exec_command(&shell, args, env);
	}
	return (0);
}
