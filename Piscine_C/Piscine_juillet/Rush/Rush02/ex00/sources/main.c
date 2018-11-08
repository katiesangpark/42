/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:41:43 by phaydont          #+#    #+#             */
/*   Updated: 2018/07/21 15:44:25 by phaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_tab	read_input(void)
{
	int		i;
	int		x;
	char	*tmp;
	char	**input;
	t_tab	tab;

	tab.length = -1;
	if ((tmp = read_file(0)) == NULL)
		return (tab);
	if ((input = split(tmp)) == NULL)
		return (tab);
	tab.input = input;
	tab.max_width = 0;
	i = -1;
	while (input[++i])
	{
		x = 0;
		while (input[i][x])
			x++;
		if (x > tab.max_width)
			tab.max_width = x;
	}
	tab.length = i;
	tab.str = tmp;
	return (tab);
}

int		main(void)
{
	int		colle;
	t_tab	file;

	colle = 0;
	file = read_input();
	if (file.length == -1)
		return (0);
	if (ft_strlen(file.str) > 1)
	{
		colle = identify_colle(file);
		if (colle == 0)
			colle = detect_shapes(file);
	}
	if (colle >= 0)
		print_colle(file, colle);
	return (0);
}
