/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:35:37 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 11:35:38 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_nbrs(int nbr1, int nbr2)
{
	ft_putchar('0' + nbr1 / 10);
	ft_putchar('0' + nbr1 % 10);
	ft_putchar(' ');
	ft_putchar('0' + nbr2 / 10);
	ft_putchar('0' + nbr2 % 10);
}

void	ft_print_comb2(void)
{
	int i;
	int a;
	int b;

	i = 1;
	while (i <= 9899)
	{
		a = i / 100;
		b = i % 100;
		if (a < b)
		{
			if (i != 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			print_nbrs(a, b);
		}
		i++;
	}
}
