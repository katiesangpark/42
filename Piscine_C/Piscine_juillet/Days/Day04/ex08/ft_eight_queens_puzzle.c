/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:13:11 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 07:13:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		abs(int value)
{
	return (value >= 0 ? value : -value);
}

int		position_valid(char *board, int y)
{
	int x;

	x = 0;
	while (x < y)
	{
		if (board[x] == board[y])
			return (0);
		if (abs(board[x] - board[y]) == abs(x - y))
			return (0);
		x++;
	}
	return (1);
}

void	place_queens(char *board, int y, int *result)
{
	board[y] = '1';
	while (board[y] <= '8')
	{
		if (position_valid(board, y))
		{
			if (y == 7)
				*result += 1;
			else
				place_queens(board, y + 1, result);
		}
		board[y]++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	char	board[9];
	int		result;

	result = 0;
	board[8] = '\0';
	place_queens(board, 0, &result);
	return (result);
}
