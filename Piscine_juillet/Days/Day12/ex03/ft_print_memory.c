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

#include "utils.h"

void	print_line(unsigned char *curr, unsigned char *end, \
					unsigned char *addr, int option)
{
	unsigned int	i;

	print_hex_line(curr, end, (unsigned char*)addr, option);
	if (option)
	{
		print(" |");
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (curr[i] < 32 || curr[i] > 126)
				ft_putchar('.');
			else
				ft_putchar(curr[i]);
			i++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size, int option)
{
	unsigned char	*curr;
	unsigned char	*end;
	int				asterisk;

	curr = (unsigned char*)addr;
	end = curr + size;
	asterisk = 0;
	while (curr < end && end - curr > 1)
	{
		if (curr + 16 >= end || (ft_memcmp(curr, curr - 16, 16) != 0))
		{
			asterisk = 0;
			print_line(curr, end, addr, option);
		}
		else if (ft_memcmp(curr, curr - 16, 16) == 0 && !asterisk)
			print_asterisk(&asterisk);
		curr += 16;
	}
	if (curr > (unsigned char*)addr)
	{
		print_hex(size, 7 + option);
		ft_putchar('\n');
	}
	return (addr);
}

void	print_asterisk(int *asterisk)
{
	*asterisk = 1;
	print("*\n");
}
