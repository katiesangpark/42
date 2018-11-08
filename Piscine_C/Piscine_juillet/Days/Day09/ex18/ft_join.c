/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:06:50 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 16:06:50 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		tabsize(char **str, int *final_len)
{
	int i;
	int x;

	i = 0;
	*final_len = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
			x++;
		*final_len += x;
		i++;
	}
	return (i);
}

char	*ft_join(char **tab, char *sep)
{
	int		x;
	int		size;
	int		final_len;
	char	*output;

	size = tabsize(tab, &final_len);
	output = malloc(final_len + ((size - 1) * ft_strlen(sep)) + 1);
	if (output == NULL)
		return (NULL);
	size = 0;
	x = 0;
	while (tab[size])
	{
		final_len = 0;
		while (tab[size][final_len])
			output[x++] = tab[size][final_len++];
		final_len = 0;
		while (tab[size + 1] && sep[final_len])
			output[x++] = sep[final_len++];
		size++;
	}
	output[x] = '\0';
	return (output);
}
