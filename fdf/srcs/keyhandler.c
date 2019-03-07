/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:10:46 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/05 23:20:03 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		keyhandler4(int key, t_window *window)
{
	if (key == KEYBOARD_NEXTFILE)
	{
		if (window->fileidx + 1 < window->filecount)
			++window->fileidx;
		else
			window->fileidx = 0;
		init_window_values(window);
	}
	else if (key == KEYBOARD_PREVFILE)
	{
		if (window->fileidx > 0)
			--window->fileidx;
		else
			window->fileidx = window->filecount - 1;
		init_window_values(window);
	}
}

static void		keyhandler3(int key, t_window *window)
{
	if (key == KEYBOARD_ROTATE_Z && window->zrot < 500)
	{
		window->zrot *= 1.1;
		window->ymove += 5;
		window->z *= 1.1;
	}
	else if (key == KEYBOARD_RESET)
		init_window_values(window);
	else if (key == KEYBOARD_DEROTATE_Z && window->zrot > 0.6)
	{
		window->zrot /= 1.1;
		window->ymove -= 5;
		if (window->z > 2)
			window->z /= 1.1;
	}
	else if (key == KEYBOARD_EXTRA && !window->extra)
		window->extra = 30;
	else if (key == KEYBOARD_EXTRA && window->extra)
		window->extra = 0;
	else
		keyhandler4(key, window);
}

static void		keyhandler2(int key, t_window *window)
{
	if (key == KEYBOARD_INC)
		window->z += 0.4 + window->zrot / 10;
	else if (key == KEYBOARD_DEC)
		window->z -= 0.4 + window->zrot / 10;
	else if (key == KEYBOARD_UP)
		window->ymove += window->h;
	else if (key == KEYBOARD_DOWN)
		window->ymove -= window->h;
	else if (key == KEYBOARD_LEFT)
		window->xmove += window->w;
	else if (key == KEYBOARD_RIGHT)
		window->xmove -= window->w;
	else if (key == KEYBOARD_ISO)
	{
		window->isometric = !window->isometric;
		window->xmove = 0;
		window->ymove = 0;
	}
	else
		keyhandler3(key, window);
}

void			keyhandler(int key, t_window *window)
{
	if (key == KEYBOARD_QUIT)
		quit_program(window);
	else if (key == KEYBOARD_ZOOM)
	{
		window->zoom += 1;
		if (window->z > 0)
			window->z += 0.1;
		window->xmove -= window->w / 2 + window->zrot;
	}
	else if (key == KEYBOARD_UNZOOM)
	{
		if (window->zoom > 0)
		{
			window->zoom -= 1;
			window->xmove += window->w / 2 + window->zrot;
		}
		if (window->z > 0.5)
			window->z -= 0.1;
	}
	else if (key == KEYBOARD_DEBUG)
		window->debug = !window->debug;
	else if (key == KEYBOARD_HUD)
		window->hud = !window->hud;
	else
		keyhandler2(key, window);
}
