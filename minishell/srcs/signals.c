/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 01:50:36 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/27 01:50:37 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include <signal.h>

t_shell	*g_shell;

void	catch_signal(int signal_id)
{
	if (signal_id == 2 && !g_shell->running_command)
	{
		ft_putstr("\b\b  \n");
		write_prompt(g_shell);
	}
}

void	signal_init(t_shell *shell)
{
	g_shell = shell;
	signal(SIGINT, catch_signal);
}
