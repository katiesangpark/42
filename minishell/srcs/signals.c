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
#include "constants.h"
#include <signal.h>

t_shell	*g_shell;

void	catch_signal(int signal_id)
{
	if (signal_id == 2 && !g_shell->running_command)
	{
		ft_putstr("\n");
		write_prompt(g_shell);
		ft_bzero(g_shell->buf, BUF_SIZE);
		g_shell->cursor = 0;
		g_shell->offset = 0;
		g_shell->bufsize = 0;
	}
}

void	signal_init(t_shell *shell)
{
	g_shell = shell;
	signal(SIGINT, catch_signal);
}
