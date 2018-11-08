/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:17:37 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 18:17:37 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex(unsigned int value, int length)
{
	char	*base;
	char	output[sizeof(int) * 2];
	int		i;

	i = 7;
	base = "0123456789abcdef";
	while (value > 0)
	{
		output[i] = base[value % 16];
		value /= 16;
		i--;
	}
	while (i >= 8 - length)
		output[i--] = '0';
	while (i < 8)
		ft_putchar(output[i++]);
}

static void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr)
{
	unsigned int i;

	i = 0;
	print_hex((unsigned int)(curr - addr), 8);
	ft_putchar(':');
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
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*curr;
	unsigned char	*end;
	unsigned int	i;

	curr = (unsigned char*)addr;
	end = curr + size;
	while (curr < end && end - curr > 1)
	{
		print_hex_line(curr, end, (unsigned char*)addr);
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (curr[i] < 32 || curr[i] > 126)
				ft_putchar('.');
			else
				ft_putchar(curr[i]);
			i++;
		}
		ft_putchar('\n');
		curr += 16;
	}
	return (addr);
}
