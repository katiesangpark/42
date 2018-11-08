/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:45:43 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 17:45:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar('0' + nbr % 10);
}

void	print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_colle(t_tab file, int colle)
{
	int		i;
	int		count;

	if ((count = count_bits(colle)) == 0)
		print("aucune");
	i = 0;
	while (i < 32 && count)
	{
		if (colle & 1)
		{
			print("[");
			print((char*)g_names[i]);
			print("]");
			print(" [");
			ft_putnbr(file.max_width);
			print("] [");
			ft_putnbr(file.length);
			print("]");
			if (--count != 0)
				print(" || ");
		}
		colle >>= 1;
		i++;
	}
	print("\n");
}
