/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:10:51 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/07 01:10:51 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_character(int x, int y, int width, int height)
{
	const static char	*charset = "oooo-| ";

	if (x == 0 && y == 0)
		ft_putchar(charset[0]);
	else if (x + 1 == width && y == 0)
		ft_putchar(charset[1]);
	else if (x == 0 && y + 1 == height)
		ft_putchar(charset[2]);
	else if (x + 1 == width && y + 1 == height)
		ft_putchar(charset[3]);
	else if (x > 0 && (y == 0 || y + 1 == height))
		ft_putchar(charset[4]);
	else if ((x == 0 || x + 1 == width) && (y != 0 && y + 1 != height))
		ft_putchar(charset[5]);
	else
		ft_putchar(charset[6]);
}

void	rush(int x, int y)
{
	int w;
	int h;

	h = 0;
	while (h < y)
	{
		w = 0;
		while (w < x)
		{
			print_character(w, h, x, y);
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}
