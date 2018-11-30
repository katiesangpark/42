/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:33:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/30 02:33:46 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	ft_putinbr(int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_putuinbr(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_putnbr_octal(unsigned int n)
{
	if (n >= 8)
		ft_putnbr(n / 8);
	ft_putchar('0' + n % 8);
}

void	ft_print_hex2(unsigned long value, char *base)
{
	char	output[32];
	int		i;

	i = 31;
	if (value == 0)
		ft_putchar(base[0]);
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (++i < 32)
		ft_putchar(output[i]);
}
