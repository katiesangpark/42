/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:59:01 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/06 00:29:52 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double			percent(int start, int end, int current)
{
	double			placement;
	double			distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static unsigned char	get_light(unsigned char start, unsigned char end,
									double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int						get_color(t_line *line)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	double			percentage;

	if (line->start_color == line->end_color)
		return (line->start_color);
	if ((line->x1 - line->x0) > (line->y1 - line->y0))
		percentage = percent(line->x0, line->x1, line->x);
	else
		percentage = percent(line->y0, line->y1, line->y);
	red = get_light((line->start_color >> 16) & 0xFF,
			(line->end_color >> 16) & 0xFF, percentage);
	green = get_light((line->start_color >> 8) & 0xFF,
			(line->end_color >> 8) & 0xFF, percentage);
	blue = get_light(line->start_color & 0xFF,
			line->end_color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
