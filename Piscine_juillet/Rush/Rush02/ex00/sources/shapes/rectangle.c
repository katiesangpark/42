/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:10:15 by phaydont          #+#    #+#             */
/*   Updated: 2018/07/21 19:27:28 by phaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*print_carre(char *str, int x)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < x)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == x - 1)
				str[index++] = 'x';
			else
				str[index++] = ' ';
			j++;
		}
		str[index++] = '\n';
		i++;
	}
	str[index] = '\0';
	return (str);
}

char	*print_rect(char *str, int x, int y)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				str[index++] = 'x';
			else
				str[index++] = ' ';
			j++;
		}
		str[index++] = '\n';
		i++;
	}
	str[index] = '\0';
	return (str);
}
