/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:59:23 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 19:07:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int abs(int value)
{
	return (value < 0 ? -value : value);
}

char *ft_itoa(int nbr)
{
	int len;
	int tmp;
	int i;
	char *output;

	len = nbr <= 0;
	tmp = nbr;
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	i = 0;
	output = malloc(len + 1);
	if (output == 0)
		return (0);
	if (nbr == 0)
		output[0] = '0';
	else if (nbr < 0)
		output[0] = '-';
	output[len] = 0;
	while (nbr != 0)
	{
		output[--len] = '0' + abs(nbr % 10);
		nbr /= 10;
	}
	return (output);
}
