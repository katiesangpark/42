/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 17:20:08 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 17:20:09 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int base_len;
	int result;
	int positive;

	i = 0;
	result = 0;
	positive = 1;
	if ((base_len = is_base_valid(base)) < 2)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			positive = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (get_char_value(str[i], base) == -1)
			return (0);
		result = result * base_len + get_char_value(str[i], base);
		i++;
	}
	return (result * positive);
}
