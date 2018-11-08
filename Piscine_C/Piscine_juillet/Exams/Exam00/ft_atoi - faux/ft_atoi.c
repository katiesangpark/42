/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:18:21 by exam              #+#    #+#             */
/*   Updated: 2018/07/06 18:26:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int i;
	int mult;

	i = 0;
	mult = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * mult);
}
