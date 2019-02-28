/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:39:44 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/26 08:31:03 by afrancoi         ###   ########.fr       */
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

void	init_signals(void)
{
	int i;

	i = 1;
	while (i < 16)
	{
		signal(i, signal_handler);
		++i;
	}
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGXCPU, signal_handler);
	signal(SIGXFSZ, signal_handler);
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

cc_t	*get_special_chars(struct termios *t)
{
	static cc_t	*chars = 0;

	if (chars == 0)
		chars = t->c_cc;
	return (chars);
}

void	init_terminal(struct termios *t)
{
	static struct termios	*termios_p = 0;
	char					buf[1024];

	if (!termios_p)
	{
		termios_p = t;
		tgetent(buf, getenv("TERM"));
		if (tcgetattr(0, &termios_p[0]) == -1
			|| tcgetattr(0, &termios_p[1]) == -1)
			exit_err_term();
		get_special_chars(termios_p);
		reset_terminal(termios_p);
		termios_p[1].c_lflag &= ~(ECHO | ICANON);
	}
	init_signals();
	tcsetattr(0, 0, &termios_p[1]);
	tputs(tgetstr("ti", NULL), 1, &ft_putchar_stdin);
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
	tputs(tgetstr("te", NULL), 1, &ft_putchar_stdin);
	tputs(tgetstr("ve", NULL), 1, &ft_putchar_stdin);
}
