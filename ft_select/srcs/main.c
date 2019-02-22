/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:39:41 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/22 07:02:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "utils.h"
#include "structs.h"
#include "terminal.h"
#include <term.h>
#include <stdlib.h>
#include <termcap.h>

static int	error_gestion(int ac, t_list **list)
{
	if (ac == 0)
	{
		ft_putendl_fd("Usage: ft_select (ARGS)", 2);
		return (0);
	}
	if ((*list = get_list(ac + 1)) == NULL)
	{
		ft_putendl_fd("Failed to allocate memory for ft_select.", 2);
		return (0);
	}
	return (1);
}

t_list		*get_list(int size)
{
	static t_list *l = NULL;

	if (l == 0)
		l = ft_memalloc(sizeof(t_list) * (size + 1));
	return (l);
}

int			main(int ac, char **av)
{
	unsigned int	cursor;
	struct termios	termios_p[2];
	t_list			*list;
	int				maxlen;
	int				retval;

	if (error_gestion(--ac, &list) == 0)
		return (0);
	cursor = 0;
	init_terminal(termios_p);
	get_list_info(&maxlen, av + 1, list);
	print_from_static(list, &cursor, &maxlen);
	while (1)
	{
		maxlen = get_list_maxlen(list);
		print_from_static(0, 0, 0);
		if ((retval = handle_input(&cursor, list, &ac)) != 0)
			break ;
	}
	reset_terminal(0);
	if (retval == 1)
		print_selected(list);
	free(list);
	return (0);
}
