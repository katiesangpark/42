/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:09:55 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 18:09:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_hex(char value)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[value / 16]);
	ft_putchar(base[value % 16]);
}

void	*ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			print_hex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}
