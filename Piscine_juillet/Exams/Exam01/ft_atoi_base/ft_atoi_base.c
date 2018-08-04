/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 18:25:05 by exam              #+#    #+#             */
/*   Updated: 2018/07/13 18:36:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int charpos(char c)
{
	char *base;
	int i;

	base = "0123456789ABCDEF";
	i = 0;
	while (base[i])
	{
		if (base[i] == c || base[i] == c - 32)
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	int result;
	int mult;

	if (str_base > 16)
		return (0);
	i = 0;
	result = 0;
	mult = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		mult = str[0] == '-' ? -1 : 1;
		i++;
	}
	while (is_number(str[i]) || is_alpha(str[i]))
	{
		result = result * str_base;
		if (charpos(str[i]) == -1)
			return (result);
		result += charpos(str[i]);
		i++;
	}
	return (result * mult);
}
