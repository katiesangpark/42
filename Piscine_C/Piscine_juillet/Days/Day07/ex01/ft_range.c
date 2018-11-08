/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:06:35 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 10:06:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*output;
	int i;

	if (max - min <= 0 || (output = malloc(sizeof(int) * (max - min))) == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		output[i] = min + i;
		i++;
	}
	return (output);
}
