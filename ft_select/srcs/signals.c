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
#include "terminal.h"
#include "utils.h"
#include <signal.h>
#include <stdlib.h>

void	suspend_event(int signo)
{
	(void)signo;
	reset_terminal(0);
	raise(SIGSTOP);
}

void	resume_event(int signo)
{
	(void)signo;
	init_terminal(0);
	print_from_static(0, 0, 0);
}

void	kill_event(int signo)
{
	(void)signo;
	reset_terminal(0);
	exit(0);
}

void	resize_event(int signo)
{
	(void)signo;
	print_from_static(0, 0, 0);
}
