/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:06:59 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 15:07:00 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	shift_tab(char **tab, int startpos, int length)
{
	while (startpos + 1 < length)
	{
		tab[startpos] = tab[startpos + 1];
		startpos++;
	}
}

int		ft_compact(char **tab, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (tab[i] == 0)
		{
			shift_tab(tab, i, length);
			printf("Detecting null at postion %d\n", i);
			i = 0;
			length--;
		}
		else
			i++;
	}
	return (length);
}
