/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:12:23 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 10:12:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*output;
	int i;

	if (max - min <= 0 || (output = malloc(sizeof(int) * (max - min))) == NULL)
		return (0);
	i = 0;
	while (i < max - min)
	{
		output[i] = min + i;
		i++;
	}
	*range = output;
	return (max - min);
}
