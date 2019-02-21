/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:48:56 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 04:48:56 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "utils.h"
#include "terminal.h"
#include <unistd.h>
#include <termcap.h>

void	get_list_info(int *maxlen, char **av, t_list *list)
{
	int i;

	i = 0;
	*maxlen = 0;
	while (av[i])
	{
		list[i].str = av[i];
		list[i].len = ft_strlen(av[i]);
		list[i].str[list[i].len] = '\n';
		list[i].selected = 0;
		if (*maxlen < list[i].len)
			*maxlen = list[i].len;
		++i;
	}
	i = -1;
	while (av[++i])
		list[i].maxlen = *maxlen;
	list[i].str = 0;
}

void	print_list_elem(t_list *list, int i, int cursor, const int maxlen)
{
	char *us;
	char *mr;
	char *me;

	mr = tgetstr("mr", NULL);
	us = tgetstr("us", NULL);
	me = tgetstr("me", NULL);
	if (cursor == i)
		tputs(us, 1, &ft_putchar_stdin);
	if (list[i].selected)
		tputs(mr, 1, &ft_putchar_stdin);
	if (list[i + 1].str == 0)
		write(0, list[i].str, list[i].len + 1);
	else
		print_with_pad(list[i].str, list[i].len, maxlen);
	tputs(me, 1, &ft_putchar_stdin);
}

void	print_list(t_list *list, unsigned int cursor, const int maxlen)
{
	t_size			size;
	unsigned int	i;
	int				max_col;
	int				column_idx;

	get_window_size(&size);
	i = -1;
	column_idx = 0;
	max_col = size.col / (maxlen + 1);
	if (max_col == 0 && (ft_putstr_fd("Window too small!\n", 0) || 1))
		return ;
	while (list[++i].str != 0)
	{
		print_list_elem(list, i, cursor, maxlen);
		if (list[i + 1].str == 0)
			break ;
		if (++column_idx >= max_col)
		{
			ft_putchar_fd('\n', 0);
			column_idx = 0;
		}
		else
			ft_putchar_fd(' ', 0);
	}
}

void	print_selected(t_list *list)
{
	unsigned int i;

	i = 0;
	while (list[i].str)
	{
		if (list[i].selected)
			write(1, list[i].str, list[i].len + 1);
		++i;
	}
}

void	print_from_static(t_list *list, unsigned int *cursor, int maxlen)
{
	static t_list		*l = 0;
	static unsigned int	*c = 0;
	static int			m = 0;

	if (!c)
		c = cursor;
	if (m == 0)
		m = maxlen;
	if (!l)
		l = list;
	else
	{
		clear_current_screen();
		print_list(l, *c, m);
	}
}
