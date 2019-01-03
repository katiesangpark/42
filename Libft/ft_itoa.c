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
#include <limits.h>

char	*ft_itoa(int n)
{
	char	*output;
	int		tmp;
	int		len;

	tmp = n;
	len = (n <= 0);
	while (tmp != 0)
	{
		++len;
		tmp /= 10;
	}
	if ((output = malloc(len + 1)) == 0)
		return (0);
	output[len] = '\0';
	if (n <= 0)
		output[0] = n < 0 ? '-' : '0';
	while (n != 0)
	{
		tmp = (n % 10);
		output[--len] = '0' + (tmp < 0 ? -tmp : tmp);
		n /= 10;
	}
	return (output);
}
