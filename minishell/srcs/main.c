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
#include "arguments.h"
#include "parsing.h"
#include "constants.h"
#include "commands.h"
#include "libft.h"
#include "shell.h"
#include "utils.h"

int		get_env_vars(t_shell *shell, char **env)
{
	char	*tmp;

	if ((shell->env = copy_env(env, NULL)) == NULL)
		return (-1);
	shell->path = get_env_var("PATH", env);
	shell->pwd = get_env_var("PWD", env);
	shell->shlvl = ft_atoi(get_env_var("SHLVL", env)) + 1;
	if ((tmp = ft_itoa(shell->shlvl)) == NULL)
		return (-1);
	set_env_var("SHLVL", tmp, shell);
	ft_strdel(&tmp);
	return (1);
}

void	write_prompt(t_shell *shell)
{
	if (shell->shlvl == 1)
		write(1, PROMPT, PROMPT_LENGTH);
	else
		ft_printf(PROMPT_SHLVL, shell->shlvl);
}

int		config_shell(t_shell *shell, int ac, char **av, char **env)
{
	ft_bzero(shell, sizeof(t_shell));
	shell->args = parse_arguments(ac, av);
	if (get_env_vars(shell, env) == -1
		|| (shell->buf = ft_strnew(BUF_SIZE)) == 0)
	{
		free_env(shell->env);
		return (0);
	}
	shell->log = LOG_INPUT;
	return (1);
}

int		main(int ac, char **av, char **env)
{
	char	**args;
	t_shell	shell;

	if (config_shell(&shell, ac, av, env) == 0)
		return (0);
	while (1)
	{
		write_prompt(&shell);
		read_input(&shell);
		if ((args = parse_input(shell.buf, &shell)) == NULL)
			continue ;
		if (exec_command(&shell, args) == -1)
			break ;
		ft_free_tab(args);
	}
	ft_free_tab(args);
	ft_strdel(&(shell.buf));
	free_env(shell.env);
	free_env(shell.alias);
	return (0);
}
