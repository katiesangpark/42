/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:37:45 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/06 23:04:12 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		free_window(t_window *win)
{
	unsigned int i;

	i = 0;
	while (i < win->filecount)
	{
		free_file(&win->file[i]);
		++i;
	}
	free(win->file);
}

void		quit_program(t_window *win)
{
	free_window(win);
	exit(0);
}

void		init_window_values(t_window *win)
{
	win->z = 2.;
	win->zrot = 2;
	win->debug = 1;
	win->hud = 1;
	win->isometric = 0;
	win->xmove = 0.;
	win->ymove = 0.;
	win->extra = 0;
	ft_memcpy(win, &win->file[win->fileidx], sizeof(t_file));
	win->zoom = (WINDOW_HEIGHT / 2) / win->h;
}

static int	hook(int key, t_window *window)
{
	keyhandler(key, window);
	window->img = mlx_new_image(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	window->framebuffer = mlx_get_data_addr(window->img,
							&(window->bpp), &(window->s_l), &(window->endian));
	draw_window(window);
	return (0);
}

int			render_window(t_window *window)
{
	init_window_values(window);
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WINDOW_WIDTH,
						WINDOW_HEIGHT, window->name);
	window->img = mlx_new_image(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	window->framebuffer = mlx_get_data_addr(window->img, &(window->bpp),
							&(window->s_l), &(window->endian));
	window->effectivebpp = window->bpp >> 3;
	draw_window(window);
	mlx_hook(window->win_ptr, 2, 0, hook, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
