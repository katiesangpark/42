/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:56:31 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/14 17:11:32 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_number_in_line(char *line, char nbr)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (line[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int		is_number_in_column(char **sudoku, int column, char nbr)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (sudoku[i][column] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int		is_number_in_grid(char **sudoku, int line, int column, char nbr)
{
	int x;
	int y;
	int startposx;
	int startposy;

	startposx = line / 3 * 3 + 3;
	startposy = column / 3 * 3 + 3;
	x = startposx - 3;
	while (x < startposx)
	{
		y = startposy - 3;
		while (y < startposy)
		{
			if (sudoku[x][y] == nbr)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int		is_number_missing(char **sudoku, int line, int column, char nbr)
{
	return (is_number_in_line(sudoku[line], nbr) == 0 &&
	is_number_in_column(sudoku, column, nbr) == 0 &&
	is_number_in_grid(sudoku, line, column, nbr) == 0);
}

int		are_arguments_valid(char **args)
{
	int i;
	int x;

	if (args == 0)
		return (0);
	x = 0;
	while (x < 9)
	{
		i = 0;
		while (args[x][i])
			i++;
		if (i != 9)
			return (0);
		x++;
	}
	return (1);
}
