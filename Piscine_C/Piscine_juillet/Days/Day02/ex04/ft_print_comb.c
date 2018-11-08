/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 11:27:58 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 11:27:58 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int i;
	int a;
	int b;

	i = 12;
	while (i <= 789)
	{
		a = i / 10 / 10;
		b = i / 10 % 10;
		if (a < b && b < i % 10)
		{
			if (i != 12)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar('0' + a);
			ft_putchar('0' + b);
			ft_putchar('0' + i % 10);
		}
		i++;
	}
}
