/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:39:05 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 01:39:06 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_arguments(int ac, char **av)
{
	int	args;

	(void)ac;
	(void)av;
	args = 0;
	return (args);
}

int		get_arg_letter(char c, int ac, char **av)
{
	int		i;
	int		x;

	i = 0;
	while (++i != ac && av[i])
	{
		if (av[i][0] != '-')
			continue ;
		x = 0;
		while (av[i][x])
		{
			if (av[i][x] == c)
				return (1);
			else if (av[i][x] == '-')
				break ;
			++x;
		}
	}
	return (0);
}

int		get_arg(char *arg, int ac, char **av)
{
	int		i;

	i = 1;
	while (i != ac && av[i])
	{
		if (ft_strcmp(av[i], arg) == 0)
			return (1);
		++i;
	}
	return (0);
}
