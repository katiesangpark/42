/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 01:05:28 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/08 01:05:28 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_char_value(char c, unsigned int base)
{
	if (c >= '0' && c <= '9' && (c - '0') < (int)base)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && (c - 'a' + 10) < (int)base)
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F' && (c - 'A' + 10) < (int)base)
		return (c - 'A' + 10);
	return (-1);
}

unsigned long	ft_atoi_base(const char *str, unsigned int base)
{
	unsigned long	result;
	int				i;
	int				tmp;

	i = 0;
	result = 0;
	if (str == 0 || base > 16)
		return (0);
	if (base == 16 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while ((tmp = get_char_value(str[i], base)) != -1)
	{
		result = result * base + tmp;
		i++;
	}
	return (result);
}

unsigned long	ft_atoi_hex(const char *str)
{
	unsigned long	result;
	int				i;
	int				tmp;

	i = 0;
	result = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while ((tmp = get_char_value(str[i], 16)) != -1)
	{
		result = result * 16 + tmp;
		++i;
	}
	return (result);
}
