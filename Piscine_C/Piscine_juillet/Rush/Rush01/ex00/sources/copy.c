/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 10:37:18 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/15 10:37:19 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i])
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	**copy_sudoku(char **sudoku)
{
	int		i;
	char	**output;

	if (sudoku == 0)
		return (NULL);
	output = malloc(sizeof(char*) * 9);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < 9)
	{
		output[i] = ft_strdup(sudoku[i]);
		if (output[i] == NULL)
			return (NULL);
		i++;
	}
	return (output);
}

void	destroy_sudoku(char **sudoku)
{
	int		x;

	if (sudoku == 0)
		return ;
	x = 0;
	while (x < 9)
	{
		if (sudoku[x] == 0)
			return ;
		free(sudoku[x]);
		x++;
	}
	free(sudoku);
}
