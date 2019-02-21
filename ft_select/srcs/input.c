/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:42:31 by kicausse          #+#    #+#             */
/*   Updated: 2019/02/20 06:42:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "structs.h"
#include <unistd.h>

static void	handle_updown_arrows(t_list *list, unsigned int *cursor,
						int list_size, int buffer)
{
	t_size			size;
	unsigned int	max_col;

	get_window_size(&size);
	max_col = size.col / list[0].maxlen;
	if (buffer == 4283163)
	{
		if (max_col != 0 && *cursor >= max_col)
			*cursor -= max_col;
	}
	else if (buffer == 4348699)
	{
		if (max_col != 0 && *cursor + max_col < (unsigned int)list_size)
			*cursor += max_col;
	}
}

static void	handle_arrows(t_list *list, unsigned int *cursor,
						int list_size, int buffer)
{
	if (buffer == 4414235)
	{
		*cursor += 1;
		if (list[*cursor].str == NULL)
			*cursor = 0;
	}
	else if (buffer == 4479771)
	{
		if (*cursor == 0)
			*cursor = list_size - 1;
		else
			*cursor -= 1;
	}
	else if (buffer == 4283163 || buffer == 4348699)
		handle_updown_arrows(list, cursor, list_size, buffer);
}

int			handle_input(unsigned int *cursor, t_list *list, int *list_size)
{
	char	buffer[9];
	int		ret;

	if ((ret = read(0, buffer, 8)) == 0 || (ret == 1 && *buffer == 27))
		return (2);
	if (ret == -1)
		return (0);
	buffer[ret] = 0;
	if (ret == 1 && *buffer == 10)
		return (1);
	if (ret == 1 && *buffer == 127)
	{
		if (remove_list_elem(list, cursor, list_size) == 0)
			return (2);
	}
	if (ret == 1 && *buffer == 32)
	{
		list[*cursor].selected = !list[*cursor].selected;
		*cursor += 1;
	}
	else if (ret == 3)
		handle_arrows(list, cursor, *list_size, *(int*)buffer);
	if (list[*cursor].str == NULL)
		*cursor = 0;
	return (0);
}
