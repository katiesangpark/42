/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 22:01:28 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/11 22:01:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_hex(unsigned int value, int length)
{
	char	*base;
	int		maxlength;
	char	output[sizeof(int) * 2];
	int		i;

	maxlength = sizeof(int) * 2;
	i = maxlength - 1;
	base = "0123456789abcdef";
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (i >= 0)
		output[i--] = '0';
	i = maxlength - length;
	while (i < maxlength)
		ft_putchar(output[i++]);
}

void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr, int option)
{
	unsigned int i;

	i = 0;
	print_hex((unsigned int)(curr - addr), 7 + option);
	ft_putchar(' ');
	if (option)
		ft_putchar(' ');
	while (i < 16)
	{
		if (curr + i < end)
			print_hex((unsigned int)curr[i], 2);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i != 15 || option)
			ft_putchar(' ');
		if (i == 7 && option)
			ft_putchar(' ');
		i++;
	}
}
