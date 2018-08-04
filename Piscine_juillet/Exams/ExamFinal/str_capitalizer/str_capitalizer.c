/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:17:14 by exam              #+#    #+#             */
/*   Updated: 2018/07/27 10:27:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char toMaj(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char toMin(char c)
{
    if (c >= 'A' && c <= 'Z')
		return (c + 32);
    return (c);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putstr_capitalizer(char *str)
{
	int i;
	char out;

	i = 0;
	while (str[i])
	{
		out = toMin(str[i]);
		if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t')
				out = toMaj(out);
		ft_putchar(out);
		i++;
	}
}

int main(int ac, char **av)
{
	int x;

	if (ac > 1)
	{
		x = 1;
		while (x < ac)
		{
			putstr_capitalizer(av[x]);
			if (++x != ac)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	return (0);
}
