/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:57:16 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 16:57:17 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		is_base_valid(char *str)
{
	int i;
	int i2;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i2 = i + 1;
		while (str[i2])
		{
			if (str[i2] == str[i])
				return (-1);
			i2++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;
	int overflow;

	if ((base_len = is_base_valid(base)) < 2)
		return ;
	overflow = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			overflow = 1;
		nbr = -nbr - overflow;
		ft_putchar('-');
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len + overflow]);
}
