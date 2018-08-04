/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:47:50 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/07 21:47:51 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *output;
	int i;

	i = 0;
	if ((output = malloc(sizeof(int) * length)) == NULL)
		return (0);
	while (i < length)
	{
		output[i] = f(tab[i]);
		i++;
	}
	return (output);
}
