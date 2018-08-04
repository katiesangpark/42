/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:49:48 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 16:49:49 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	init_charset(char *charset)
{
	int	i;

	i = 0;
	while (i < 7)
		charset[i++] = '.';
	charset[i] = '\0';
}

int		is_valid_colle(char **input)
{
	int		x;
	int		y;
	int		first_line;

	x = 0;
	first_line = -1;
	while (input[x])
	{
		y = 0;
		while (input[y])
			y++;
		if (first_line == -1)
			first_line = y;
		else if (first_line != y)
			return (0);
		x++;
	}
	return (first_line != -1);
}

int		identify_colle(t_tab file)
{
	char	charset[8];

	if (!is_valid_colle(file.input))
		return (0);
	init_charset(charset);
	charset[0] = file.input[0][0];
	if (file.max_width > 1)
	{
		charset[1] = file.input[0][file.max_width - 1];
		if (file.max_width > 2)
			charset[4] = file.input[0][1];
	}
	if (file.length > 1)
	{
		charset[2] = file.input[file.length - 1][0];
		if (file.max_width > 1)
			charset[3] = file.input[file.length - 1][file.max_width - 1];
		if (file.length > 2)
		{
			charset[5] = file.input[1][0];
			if (file.max_width > 2)
				charset[6] = file.input[1][1];
		}
	}
	return (get_colle(file, charset));
}

int		validate_colle(t_tab file, int colle)
{
	int	x;
	int	y;
	int	c;

	if (colle == 0)
		return (0);
	x = 0;
	c = get_colle_from_bit(colle);
	while (file.input[x])
	{
		y = 0;
		while (file.input[x][y])
		{
			if (c_find(g_charset[c], file.input[x][y]) == -1)
				return (0);
			if (y > 0 && y + 1 < file.max_width &&
				x > 0 && x + 1 < file.length &&
				file.input[x][y] != g_charset[c][6])
				return (0);
			y++;
		}
		x++;
	}
	return (colle);
}

int		get_colle(t_tab file, char *charset)
{
	int	colle;

	colle = 0;
	if (match_strings(charset, g_charset[0]))
		colle |= COLLE00;
	if (match_strings(charset, g_charset[1]))
		colle |= COLLE01;
	if (match_strings(charset, g_charset[2]))
		colle |= COLLE02;
	if (match_strings(charset, g_charset[3]))
		colle |= COLLE03;
	if (match_strings(charset, g_charset[4]))
		colle |= COLLE04;
	colle = validate_colle(file, colle);
	if (colle != 0 && find_character(charset, '.', 4) == -1)
	{
		colle |= COLLE_RECTANGLE;
		if (file.length == file.max_width)
			colle |= COLLE_SQUARE;
	}
	return (colle);
}
