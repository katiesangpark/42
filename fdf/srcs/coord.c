/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 00:36:02 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/06 23:02:12 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	coord_assign(t_coord *coord, t_line *line)
{
	coord->dx = abs(line->x1 - line->x0);
	coord->sx = line->x0 < line->x1 ? 1 : -1;
	coord->dy = abs(line->y1 - line->y0);
	coord->sy = line->y0 < line->y1 ? 1 : -1;
	coord->err = (coord->dx > coord->dy ? coord->dx : -coord->dy) / 2;
	line->x = line->x0;
	line->y = line->y0;
}
