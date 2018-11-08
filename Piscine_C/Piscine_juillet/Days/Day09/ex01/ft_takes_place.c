/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 23:45:21 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/12 23:45:22 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	convert_hour(int *hour, int *next_hour)
{
	if (*hour >= 12)
		*hour -= (*hour == 12 ? 0 : 12);
	else if (*hour == 0)
		*hour = 12;
	*next_hour = *hour + 1;
	if (*next_hour >= 12)
		*next_hour -= (*next_hour == 12 ? 0 : 12);
	else if (*next_hour == 0)
		*next_hour = 12;
}

void	ft_takes_place(int hour)
{
	static char	s[2][5] = {"A.M.", "P.M."};
	const char	*format;
	int			next_hour;
	int			period[2];

	format = "THE FOLLOWING TAKES PLACE BETWEEN %02d.00 %s AND %02d.00 %s\n";
	period[0] = hour >= 12;
	if (hour == 24)
		period[0] = 0;
	period[1] = hour + 1 >= 12;
	if (hour + 1 >= 24)
		period[1] = 0;
	convert_hour(&hour, &next_hour);
	printf(format, hour, s[period[0]], next_hour, s[period[1]]);
}
