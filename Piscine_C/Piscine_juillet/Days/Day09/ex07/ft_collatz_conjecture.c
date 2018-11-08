/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:48:30 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 01:48:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	static int	i;

	if (base == 1)
		return (i == 0 ? 1 : i);
	i++;
	if (base & 1)
		return (ft_collatz_conjecture(base * 3 + 1));
	return (ft_collatz_conjecture(base / 2));
}
