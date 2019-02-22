/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 05:18:40 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/21 05:18:41 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "utils.h"
#include "terminal.h"
#include <signal.h>
#include <stdlib.h>

void		signal_handler(int signo)
{
	ft_printf_fd(0, "%d\n", signo);
	if (signo == 18)
	{
		reset_terminal(0);
		raise(SIGSTOP);
	}
	if (signo == 19)
	{
		init_terminal(0);
		print_from_static(0, 0, 0);
	}
	if (signo == 2)
	{
		reset_terminal(0);
		free(get_list(0));
		exit(0);
	}
	if (signo == 28)
		print_from_static(0, 0, 0);
}
