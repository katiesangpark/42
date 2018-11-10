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

static void	print_hex_line(unsigned char *curr, unsigned char *end, \
						unsigned char *addr)
{
	unsigned int i;

	i = 0;
	ft_print_hex((unsigned int)(curr - addr), 8);
	ft_putchar(':');
	ft_putchar(' ');
	while (i < 16)
	{
		if (curr + i < end)
			ft_print_hex((unsigned int)curr[i], 2);
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
	while (curr < end)
	{
		print_hex_line(curr, end, (unsigned char*)addr);
		i = 0;
		while (i < 16 && curr + i < end)
		{
			if (!ft_isprint(curr[i]))
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
