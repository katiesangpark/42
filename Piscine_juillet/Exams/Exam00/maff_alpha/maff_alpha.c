/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:09:29 by exam              #+#    #+#             */
/*   Updated: 2018/07/06 18:12:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char c;

	(void)argc;
	(void)argv;
	c = 'a';
	while (c <= 'z')
	{
		ft_putchar(c % 2 ? c : c - 32);
		c++;
	}
	ft_putchar('\n');
	return (0);
}
