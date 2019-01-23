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
	ft_bzero(shell, sizeof(t_shell));
	shell->path = get_env_var("PATH", env);
	shell->pwd = get_env_var("PWD", env);
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
