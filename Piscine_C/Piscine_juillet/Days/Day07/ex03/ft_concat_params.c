/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:14:34 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 10:14:35 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_total_length(char **tab, int size)
{
	int i;
	int total_length;

	total_length = 0;
	while (size > 0)
	{
		size--;
		i = 0;
		while (tab[size][i])
			i++;
		total_length += i;
	}
	return (total_length);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		x;
	int		offset;

	argv++;
	argc--;
	str = malloc(sizeof(char) * (get_total_length(argv, argc) + argc));
	x = 0;
	offset = 0;
	while (x < argc)
	{
		i = 0;
		while (argv[x][i])
		{
			str[offset++] = argv[x][i];
			i++;
		}
		str[offset++] = '\n';
		x++;
	}
	str[offset - 1] = '\0';
	return (str);
}
