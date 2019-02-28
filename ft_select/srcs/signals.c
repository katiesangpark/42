/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 05:18:40 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/26 08:30:36 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "utils.h"
#include "terminal.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>

void		reset_signals(void)
{
	int i;

	i = 1;
	while (i <= 31)
	{
		if (i != SIGCONT)
			signal(i, SIG_DFL);
		++i;
	}
}

void		signal_handler(int signo)
{
	char buf[2];

	if (signo == 18)
	{
		reset_terminal(0);
		reset_signals();
		buf[0] = get_special_chars(0)[VSUSP];
		buf[1] = 0;
		ioctl(0, TIOCSTI, buf);
	}
	else if (signo == 19)
	{
		init_terminal(0);
		print_from_static(0, 0, 0);
	}
	else if (signo < 16 || signo >= 30 || (signo >= 24 && signo <= 27))
	{
		reset_terminal(0);
		free(get_list(0));
		exit(0);
	}
	else if (signo == 28)
		print_from_static(0, 0, 0);
}
