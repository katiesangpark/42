/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:30:35 by exam              #+#    #+#             */
/*   Updated: 2018/07/20 18:34:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(int ac, char **av)
{
	int i;
	if (ac == 2)
	{
		i = -1;
		while (av[1][++i])
		{
			if (!is_alpha(av[1][i]))
				continue;
			if (av[1][i] == 'z' || av[1][i] == 'Z')
				av[1][i] -= 25;
			else
				av[1][i] += 1;
		}
		write(1, av[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
