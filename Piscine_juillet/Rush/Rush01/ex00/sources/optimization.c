/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 08:09:36 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/15 08:09:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		occurence_in_line(char *line, char nbr)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (i < 9)
	{
		if (line[i] == nbr)
			amount++;
		i++;
	}
	return (amount);
}

int		occurence_in_column(char **sudoku, int column, char nbr)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (i < 9)
	{
		if (sudoku[i][column] == nbr)
			amount++;
		i++;
	}
	return (amount);
}

int		occurence_in_grid(char **sudoku, int line, int column, char nbr)
{
	int	x;
	int	y;
	int	startposx;
	int	startposy;
	int	amount;

	startposx = line / 3 * 3 + 3;
	startposy = column / 3 * 3 + 3;
	amount = 0;
	x = startposx - 3;
	while (x < startposx)
	{
		y = startposy - 3;
		while (y < startposy)
		{
			if (sudoku[x][y] == nbr)
				amount++;
			y++;
		}
		x++;
	}
	return (amount);
}
