/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:10:15 by phaydont          #+#    #+#             */
/*   Updated: 2018/07/21 19:27:28 by phaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_carre(int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == x - 1)
				write(1, "x", 1);
			else
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int total;

	total = 0;
	while (*str != '\0')
	{
		total = total * 10 + *str - '0';
		str++;
	}
	return (total);
}

int		main(int argc, char **argv)
{
	int	x;

	if (argc == 2)
	{
		x = ft_atoi(argv[1]);
		print_carre(x);
	}
	return (0);
}
