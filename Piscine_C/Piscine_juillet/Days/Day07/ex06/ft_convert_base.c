/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:48:33 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 11:48:34 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		get_char_value(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*write_nbr_base(int nb, int length, int base_len, char *base_to)
{
	char *nbr;

	nbr = malloc(sizeof(char) * length);
	nbr[length - 1] = '\0';
	if (nb == 0)
		nbr[0] = base_to[0];
	else
	{
		length--;
		while (nb != 0)
		{
			nbr[--length] = base_to[nb % base_len];
			nb /= base_len;
		}
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	int nb;
	int base_len;
	int length;

	if ((base_len = is_base_valid(base_from)) < 2 || is_base_valid(base_to) < 2)
		return (NULL);
	i = 0;
	nb = 0;
	while (nbr[i])
		nb = nb * base_len + get_char_value(nbr[i++], base_from);
	i = nb;
	length = (nb == 0) + 1;
	base_len = is_base_valid(base_to);
	while (i != 0)
	{
		i /= base_len;
		length++;
	}
	return (write_nbr_base(nb, length, base_len, base_to));
}
