/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:26:07 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 13:26:08 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*strdup_line(char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int		count_cases(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**split(char *str)
{
	int		i;
	int		x;
	int		len;
	char	**output;

	len = count_cases(str);
	output = malloc(sizeof(char*) * (len + 1));
	if (len == 0 || output == 0)
		return (0);
	i = 0;
	x = 0;
	while (str[i])
	{
		output[x++] = strdup_line(str + i);
		if (output[x - 1] == 0)
			return (0);
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	output[x] = 0;
	return (output);
}

void	destroy_map(char *map)
{
	if (map != 0)
		free(map);
}

void	destroy_grid(char **grid)
{
	int	i;

	if (grid == 0)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
