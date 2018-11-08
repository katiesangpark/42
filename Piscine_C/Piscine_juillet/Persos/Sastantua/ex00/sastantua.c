/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 23:11:14 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/06 23:11:15 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_max(int size)
{
	int floor;
	int	width;
	int	step;
	int extra;

	floor = 0;
	width = 1;
	extra = 0;
	while (floor < size)
	{
		step = 0;
		if (floor > 0)
			extra += (floor % 2 == 0) * 2;
		while (step < 3 + floor)
		{
			width += 2;
			step++;
		}
		if (++floor != size)
			width += 4 + extra;
	}
	return (width);
}

void	print_padding(int padding)
{
	while (padding-- >= 0)
		ft_putchar(' ');
}

void	print_line(int width, int floor, int last_floor, int cstep)
{
	int	i;
	int	door_size;

	i = 2;
	door_size = floor / 2;
	ft_putchar('/');
	while (i < width)
	{
		if (last_floor && (i >= width / 2 - door_size + 1
			&& i <= width / 2 + door_size + 1) &&
			(cstep <= door_size * 2 + 1))
		{
			if (door_size >= 2 && i == width / 2 + door_size
				&& cstep == door_size + 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else
			ft_putchar('*');
		i++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int floor;
	int	width;
	int	step;
	int	max_width;
	int extra;

	extra = 0;
	floor = 0;
	width = 1;
	max_width = get_max(size);
	while (floor < size)
	{
		step = 0;
		if (floor > 0)
			extra += (floor % 2 == 0) * 2;
		while (step < 3 + floor)
		{
			width += 2;
			print_padding((max_width - width) / 2 - 1);
			print_line(width, floor, floor + 1 == size, 3 + floor - step);
			step++;
		}
		width += 4 + extra;
		floor++;
	}
}
