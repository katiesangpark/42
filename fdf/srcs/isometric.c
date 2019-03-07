/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:24:34 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/06 23:02:19 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		isometric(t_line *line, int z)
{
	int		tmp;

	tmp = line->x0;
	line->x0 = (tmp - line->y0) * cos(0.46373398);
	line->y0 = -z + (tmp + line->y0) * sin(0.46373398);
	tmp = line->x1;
	line->x1 = (tmp - line->y1) * cos(0.46373398);
	line->y1 = -z + (tmp + line->y1) * sin(0.46373398);
}
