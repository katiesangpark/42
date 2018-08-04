/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:50:21 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 18:54:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int mult;
    int result;

    mult = 1;
    i = 0;
    result = 0;
    while (str[i] == '\n' || str[i] == '\v' ||
           str[i] == '\r' || str[i] == '\t')
        i++;
    if (str[i] == '-')
        mult = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * mult);
}

int biggest_divider(int n1, int n2)
{
	int div;
	int max;

	div = 2;
	max = 1;
	while (div < n1 && div < n2)
	{
		if (n1 % div == 0 && n2 % div == 0)
			max = div;
		div++;
	}
	return (max);
}

int main(int ac, char **av)
{
	int n1;
	int n2;

	if (ac == 3)
	{
		n1 = ft_atoi(av[1]);
		n2 = ft_atoi(av[2]);
		printf("%d", biggest_divider(n1, n2));
	}
	printf("\n");
	return (0);
}
