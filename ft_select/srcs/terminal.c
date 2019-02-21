/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:39:44 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 06:39:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "terminal.h"
#include <stdlib.h>
#include <signal.h>

void	clear_current_screen(void)
{
	char	*cl;

	cl = tgetstr("cl", NULL);
	tputs(cl, 1, &ft_putchar_stdin);
}

void	init_terminal(struct termios *t)
{
	static struct termios	*termios_p = 0;
	char					buf[1024];

	if (!termios_p)
	{
		termios_p = t;
		tgetent(buf, getenv("TERM"));
		tcgetattr(0, &termios_p[0]);
		tcgetattr(0, &termios_p[1]);
		reset_terminal(termios_p);
		termios_p[1].c_lflag &= ~(ECHO | ICANON);
		signal(SIGWINCH, resize_event);
		signal(SIGINT, kill_event);
		signal(SIGCONT, resume_event);
		signal(SIGSTOP, suspend_event);
		signal(SIGTSTP, suspend_event);
	}
	tcsetattr(0, 0, &termios_p[1]);
	tputs(tgetstr("vi", NULL), 1, &ft_putchar_stdin);
}

void	reset_terminal(struct termios *termios_p)
{
	static struct termios *t = 0;

	if (!t)
	{
		t = termios_p;
		return ;
	}
	tcsetattr(0, 0, t);
	tputs(tgetstr("ve", NULL), 1, &ft_putchar_stdin);
	clear_current_screen();
}
