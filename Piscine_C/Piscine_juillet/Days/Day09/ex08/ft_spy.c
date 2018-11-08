/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 01:59:54 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/13 01:59:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	to_min(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		k_strfind(char *str, char *to_find, int *len)
{
	int i;
	int i2;

	i = 0;
	while (str[i] != '\0')
	{
		i2 = 0;
		while (to_min(str[i + i2]) == to_min(to_find[i2]) && str[i + i2])
			i2++;
		if (to_find[i2] == '\0')
		{
			*len = ft_strlen(to_find);
			return (i);
		}
		i++;
	}
	if (str[0] == '\0' && to_find[0] == '\0')
		return (0);
	return (-1);
}

int		main(int argc, char **argv)
{
	int	alert;
	int	i;
	int	pos;
	int len;

	alert = 0;
	i = 1;
	while (!alert && i < argc)
	{
		if ((pos = k_strfind(argv[i], "president", &len)) >= 0 ||
			(pos = k_strfind(argv[i], "attack", &len)) >= 0 ||
			(pos = k_strfind(argv[i], "bauer", &len)) >= 0)
		{
			alert = 1;
			if (pos != 0 && argv[i][pos - 1] != ' ')
				alert = 0;
			else if (argv[i][pos + len] != '\0' && argv[i][pos + len] != ' ')
				alert = 0;
		}
		i++;
	}
	if (alert)
		write(1, "Alert!!!\n", 9);
	return (0);
}
