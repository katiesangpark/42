/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:35:03 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 01:35:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_destroy(char ***factory)
{
	int i;
	int x;

	if (factory == 0)
		return ;
	i = 0;
	while (factory[i] != 0)
	{
		x = 0;
		while (factory[i][x] != 0)
		{
			free(factory[i][x]);
			x++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}
