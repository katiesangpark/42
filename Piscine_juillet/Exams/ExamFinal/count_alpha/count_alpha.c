/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:44:32 by exam              #+#    #+#             */
/*   Updated: 2018/07/27 10:58:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char to_min(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int alpha_char_after(char c2, char *str)
{
	int i;
	char c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			if (to_min(c) != to_min(c2))
				return (1);
		i++;
	}
	return (0);
}	

int count_chars(char *str)
{
	int occurence;
	char c;
	int i;

	c = str[0];
	occurence = 1;
	i = 1;
	while (str[i])
	{
		if (to_min(c) == to_min(str[i]))
		{
			occurence++;
			str[i] = -1;
		}
		i++;
	}
	return (occurence);
}

int main(int ac, char **av)
{
	int i;
	int occ;
	char c;

	if (ac == 2)
	{
		occ = 0;
		i = 0;
		while (av[1][i])
		{
			c = av[1][i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (occ == 0)
				{
					occ = count_chars(av[1] + i);
					printf("%d%c", occ, to_min(c));
				}
				else
				{
					occ = count_chars(av[1] + i);
					printf(" %d%c", occ, to_min(c));
				}
				if (alpha_char_after(c, av[1] + i))
					printf(",");
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
