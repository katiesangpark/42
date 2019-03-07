/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:56:22 by kicausse          #+#    #+#             */
/*   Updated: 2019/03/04 23:06:34 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		get_data_count(char *line)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			++i;
		++len;
		while (line[i] && line[i] != ' ')
			++i;
		while (line[i] == ' ')
			++i;
	}
	return (len);
}

void	free_tab_len(char **tab, int len)
{
	while (len > 0 && tab)
		ft_strdel(&tab[--len]);
	free(tab);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
	{
		ft_strdel(&tab[i]);
		++i;
	}
	free(tab);
}

char	*write_nbr_to_buffer(char *buffer, long nbr, size_t bufsize)
{
	int i;
	int neg;

	if (bufsize <= 1)
	{
		buffer[0] = '\0';
		return (buffer);
	}
	i = bufsize - 1;
	buffer[--i] = '\0';
	neg = nbr < 0;
	if (nbr == 0)
		buffer[--i] = '0';
	while (i >= 0 && nbr != 0)
	{
		buffer[--i] = '0' + ft_abs(nbr % 10);
		nbr /= 10;
	}
	if (i >= 0 && neg)
		buffer[--i] = '-';
	return (i <= 0 ? buffer : buffer + i);
}
