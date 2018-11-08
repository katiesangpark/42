/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phaydont <phaydont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:11:52 by phaydont          #+#    #+#             */
/*   Updated: 2018/07/22 15:05:54 by phaydont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_rond(int n, int inverted)
{
	int					x;
	int					y;
	static const char	*charset = "x ";

	x = -n + 1;
	while (x < n)
	{
		y = -n + 1;
		while (y < n)
		{
			if (x * x + y * y < (n * n) - 2 * n)
				write(1, charset + inverted, 1);
			else
				write(1, charset + (1 + inverted) % 2, 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}
