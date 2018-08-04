/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:13:11 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 07:13:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

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

void	place_queens(char *board, int y)
{
	board[y] = '1';
	while (board[y] <= '8')
	{
		if (position_valid(board, y))
		{
			if (y == 7)
			{
				ft_putstr(board);
				ft_putchar('\n');
			}
			else
				place_queens(board, y + 1);
		}
		board[y]++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	char	board[9];

	board[8] = '\0';
	place_queens(board, 0);
}
