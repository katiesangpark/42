/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 01:10:19 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/07 18:20:55 by mgessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int		main(int argc, char **argv)
{
	int	width;
	int	height;

	width = 5;
	height = 5;
	if (argc > 1)
		width = ft_atoi(argv[1]);
	if (argc > 2)
		height = ft_atoi(argv[2]);
	if (height <= 0 || width <= 0)
	{
		ft_putstr("Error: Please specifiy a width and height higher than 0.\n");
		return (0);
	}
	rush(width, height);
	return (0);
}
