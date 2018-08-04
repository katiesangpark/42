/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:41:51 by exam              #+#    #+#             */
/*   Updated: 2018/07/27 10:43:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int value, int base)
{
    char *output;
    char *strbase = "0123456789ABCDEF";
    int neg;
    int len;
    unsigned int tmp;

    neg = value < 0;
    len = value <= 0;
    tmp = value > 0 ? value : -value;
    while (tmp != 0)
    {
        len++;
        tmp /= base;
    }
    if (neg && base != 10)
        len--;
    output = malloc(len + 1);
    output[len] = '\0';
    output[0] = neg ? '-' : strbase[0];
    tmp = value > 0 ? value : -value;
    while (tmp != 0)
    {
        output[--len] = strbase[tmp % base];
        tmp /= base;
    }
    return (output);
}
