/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:08:11 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 16:08:11 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < length)
	{
		x = 0;
		count = 0;
		while (x < length)
		{
			if (tab[x] == tab[i])
				count++;
			x++;
		}
		if (count % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
