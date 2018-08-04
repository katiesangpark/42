/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:01:07 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/20 10:01:08 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_atoi(char *str, int end)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (i < end && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (i != end)
		return (0);
	return (result);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_strncpy(char *dest, char *src, int dest_len)
{
	int i;

	i = 0;
	while (src[i] && i < dest_len)
	{
		dest[i] = src[i];
		i++;
	}
}
