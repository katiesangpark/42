/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:39:41 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 01:39:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "utils.h"
#include "structs.h"
#include "terminal.h"
#include <term.h>
#include <termcap.h>

int		main(int ac, char **av)
{
	unsigned int	cursor;
	struct termios	termios_p[2];
	t_list			list[ac];
	int				maxlen;
	int				retval;

	if (--ac == 0)
	{
		ft_putendl("Usage: ft_select (ARGS)");
		return (0);
	}
	cursor = 0;
	init_terminal(termios_p);
	get_list_info(&maxlen, av + 1, list);
	print_from_static(list, &cursor, maxlen);
	while (1)
	{
		print_from_static(0, 0, 0);
		if ((retval = handle_input(&cursor, list, &ac)) != 0)
			break ;
	}
	reset_terminal(0);
	if (retval == 1)
		print_selected(list);
	return (0);
}
