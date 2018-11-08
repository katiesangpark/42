/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:40:07 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 19:50:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
	char *basestr = "0123456789ABCDEF";
    char *output;
    int tmp;
    int len;
    int neg;


    neg = value < 0;
    len = value <= 0;
    tmp = value;
	if (base < 2 || base > 16)
		return (0);
	if (base != 10 && neg)
	{
		neg = 0;
		len = 0;
	}
    while (tmp != 0)
    {
		tmp /= base;
        len++;
    }
    output = malloc(len + 1);
	if (output == 0)
		return (0);
    output[0] = basestr[0];
    output[len] = 0;
    while (len-- >= 0)
    {
        if (value % base > 0)
			output[len] = basestr[value % base];
        else
            output[len] = basestr[-(value % base)];
        value /= base;
    }
    if (neg && base == 10)
        output[0] = '-';
    return (output);
}
