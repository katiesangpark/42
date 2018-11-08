/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:44:32 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 10:44:33 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copy_word(char *src)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] > 32)
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] > 32)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int		count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			count++;
			while (str[i] > 32)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

char	**ft_split_whitespaces(char *str)
{
	char	**output;
	int		i;
	int		x;

	if ((output = malloc(sizeof(char*) * count_words(str))) == NULL)
		return (NULL);
	x = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			if ((output[x] = copy_word(str + i)) == NULL)
				return (NULL);
			while (str[i] > 32)
				i++;
			x++;
		}
		else
			i++;
	}
	output[x] = 0;
	return (output);
}
