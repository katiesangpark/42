/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcausse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:31:58 by kcausse           #+#    #+#             */
/*   Updated: 2018/02/26 21:31:59 by kcausse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int i2;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	i2 = 0;
	while (argv[2][i] != '\0' && argv[1][i2] != '\0')
	{
		if (argv[1][i2] == argv[2][i])
			i2++;
		i++;
	}
	write(1, argv[1][i2] == '\0' ? "1\n" : "0\n", 2);
	return (0);
}
