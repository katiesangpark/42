/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 00:13:47 by cgilbert          #+#    #+#             */
/*   Updated: 2018/07/15 12:18:40 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		is_sudoku_valid(int argc, char **sudoku)
{
	int x;
	int y;
	int count;

	if (argc != 10)
		return (0);
	x = 0;
	count = 0;
	while (x < 9)
	{
		y = -1;
		while (++y < 9)
		{
			if (sudoku[x][y] == '.')
				continue ;
			if (occurence_in_line(sudoku[x], sudoku[x][y]) != 1 ||
				occurence_in_column(sudoku, y, sudoku[x][y]) != 1 ||
				occurence_in_grid(sudoku, x, y, sudoku[x][y]) != 1 ||
				sudoku[x][y] < '0' || sudoku[x][y] > '9')
				return (0);
			count++;
		}
		x++;
	}
	return (count);
}

int		resolve_sudoku(char **sudoku, int n, int *result, char ***output)
{
	int	line;
	int	column;

	if (*result > 1)
		return (0);
	if (n > 88)
	{
		if (*result == 0)
			*output = copy_sudoku(sudoku);
		if (*output == 0)
			*result = 1;
		*result += 1;
		return (1);
	}
	line = n / 10;
	column = n % 10;
	if (sudoku[line][column] != '.')
		return (resolve_sudoku(sudoku, n + 1, result, output));
	fill_case(sudoku, n, result, output);
	return (0);
}

void	fill_case(char **sudoku, int n, int *result, char ***output)
{
	int		line;
	int		column;
	char	nbr;

	line = n / 10;
	column = n % 10;
	nbr = '0';
	while (++nbr <= '9')
	{
		if (*result <= 1 && is_number_missing(sudoku, line, column, nbr))
		{
			sudoku[line][column] = nbr;
			resolve_sudoku(sudoku, n + 1, result, output);
		}
	}
	sudoku[line][column] = '.';
}

int		main(int argc, char **argv)
{
	char	**sudoku;
	char	**output;
	int		result;
	int		count;

	sudoku = argv + 1;
	count = is_sudoku_valid(argc, sudoku);
	if (count < 17)
	{
		print("Error\n");
	}
	else
	{
		result = 0;
		resolve_sudoku(sudoku, 0, &result, &output);
		if (result == 1)
			print_sudoku(output);
		else
			print("Error\n");
		destroy_sudoku(output);
	}
	return (0);
}
