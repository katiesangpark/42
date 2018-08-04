/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:43:52 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/03 11:43:53 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int x;
	int i;

	x = 0;
	while (tab[x])
	{
		i = 0;
		while (tab[x][i])
		{
			ft_putchar(tab[x][i]);
			i++;
		}
		x++;
		ft_putchar('\n');
	}
}
