/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:23:56 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 19:23:57 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_length(int nbr)
{
	int len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*output;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = nbr_length(n);
	output = (char*)malloc(len + 1);
	if (output == 0)
		return (0);
	output[len] = 0;
	output[0] = '0';
	if (n < 0)
		output[0] = '-';
	while (n != 0)
	{
		output[--len] = '0' + (ft_abs(n) % 10);
		n /= 10;
	}
	return (output);
}