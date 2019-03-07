/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:36:06 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/04 23:04:47 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

static void				print_string(t_window *win, int x, int y, char *str)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y, TEXT_COL, str);
}

static void				print_box(t_window *win, int x, int y)
{
	while (y <= WINDOW_HEIGHT / 16)
	{
		x = 0;
		while (x <= WINDOW_WIDTH)
			write_pixel(win, x++, y, TITLEBAR_COL);
		y++;
	}
	x = WINDOW_WIDTH - (HUD_WIDTH + HUD_WOFFSET);
	y = WINDOW_HEIGHT / 10 - 10;
	while (x <= (WINDOW_WIDTH - HUD_WOFFSET))
		write_pixel(win, x++, y, HUDBORDER_COL);
	while (y <= WINDOW_HEIGHT / 10 + (HUD_HEIGHT + 5))
		write_pixel(win, x, y++, HUDBORDER_COL);
	while (x >= WINDOW_WIDTH - (HUD_WIDTH + HUD_WOFFSET))
		write_pixel(win, x--, y, HUDBORDER_COL);
	while (y >= WINDOW_HEIGHT / 10 - 10)
		write_pixel(win, x, y--, HUDBORDER_COL);
	y = WINDOW_HEIGHT / 10 - 5;
	while (y < WINDOW_HEIGHT / 10 + HUD_HEIGHT)
	{
		x = WINDOW_WIDTH - (HUD_WIDTH + HUD_WOFFSET - 5);
		while (x < WINDOW_WIDTH - (HUD_WOFFSET + 5))
			write_pixel(win, x++, y, HUDBG_COL);
		y++;
	}
}

static void				print_log(t_window *win)
{
	char buffer[32];

	print_string(win, 50, WINDOW_HEIGHT / 10, "Z:");
	print_string(win, 200, WINDOW_HEIGHT / 10,
				write_nbr_to_buffer(buffer, win->z, 32));
	print_string(win, 50, WINDOW_HEIGHT / 10 + 20, "Z Axis:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 20,
				write_nbr_to_buffer(buffer, win->zrot, 32));
	print_string(win, 50, WINDOW_HEIGHT / 10 + 40, "Zoom:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 40,
				write_nbr_to_buffer(buffer, win->zoom, 32));
	print_string(win, 50, WINDOW_HEIGHT / 10 + 60, "Pos X:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 60,
				write_nbr_to_buffer(buffer, win->xmove, 32));
	print_string(win, 50, WINDOW_HEIGHT / 10 + 80, "Pos Y:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 80,
				write_nbr_to_buffer(buffer, win->ymove, 32));
	print_string(win, 50, WINDOW_HEIGHT / 10 + 100, "Projection:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 100,
			win->isometric ? "2:1 Isometric" : "Isometric");
	print_string(win, 50, WINDOW_HEIGHT / 10 + 120, "Mode:");
	print_string(win, 200, WINDOW_HEIGHT / 10 + 120,
			win->extra ? "Extra" : "Normal");
}

static void				print_txt(t_window *win)
{
	print_string(win, 5, W_H - 20, win->name);
	print_string(win, HUDX, W_H / 10, "[ESC] Exit");
	print_string(win, HUDX, W_H / 10 + 20, "[+/-] Zoom In/Out");
	print_string(win, HUDX, W_H / 10 + 40, "[W] Inc Height");
	print_string(win, HUDX, W_H / 10 + 60, "[S] Dec Height");
	print_string(win, HUDX, W_H / 10 + 80, "[D] Debug Mode");
	print_string(win, HUDX, W_H / 10 + 100, "[H] HUD On/Off");
	print_string(win, HUDX, W_H / 10 + 120, "[7 - 8] Z-Axis");
	print_string(win, HUDX, W_H / 10 + 140, "[R] Reset");
	print_string(win, HUDX, W_H / 10 + 160, "[I] = Switch View");
	print_string(win, HUDX, W_H / 10 + 180, "[E] = Extra Mode");
	print_string(win, HUDX, W_H / 10 + 200, "Arrows = Movement");
	print_string(win, HUDX, W_H / 10 + 220, "PGUP = Next file");
	print_string(win, HUDX, W_H / 10 + 240, "PGDN = Prev file");
	print_string(win, W_W / 2, 12, "FDF");
}

void					draw_window(t_window *win)
{
	draw_map(win);
	if (win->hud)
		print_box(win, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 0, 0);
	if (win->hud)
	{
		print_txt(win);
		if (win->debug)
			print_log(win);
	}
}
