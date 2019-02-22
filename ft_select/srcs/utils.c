/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 02:47:11 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 02:47:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include <unistd.h>
#include <sys/ioctl.h>

int		get_list_maxlen(t_list *list)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (list[i].str)
	{
		if (list[i].len > max)
			max = list[i].len;
		++i;
	}
	while (list[0].str)
	{
		list[0].maxlen = max;
		++list;
	}
	return (max);
}

int		remove_list_elem(t_list *list, unsigned int *cursor, int *list_size)
{
	int i;

	if (*list_size - 1 == (int)*cursor)
	{
		list[*cursor].str = 0;
		*list_size -= 1;
		*cursor -= 1;
	}
	else
	{
		i = *cursor;
		while (list[i].str)
		{
			list[i].str = list[i + 1].str;
			list[i].len = list[i + 1].len;
			list[i].selected = list[i + 1].selected;
			++i;
		}
		*list_size -= 1;
	}
	return (*list_size > 0);
}

void	get_window_size(t_size *size)
{
	ioctl(0, TIOCGWINSZ, (struct winsize*)size);
}

void	print_with_pad(char *str, int len, int maxlen)
{
	unsigned int i;

	write(0, str, len);
	i = maxlen - len;
	while (i > 0)
	{
		write(0, " ", 1);
		--i;
	}
}

int		ft_putchar_stdin(int c)
{
	return (write(0, &c, 1));
}
