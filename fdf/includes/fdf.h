/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:30:44 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/04 23:33:56 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH			(1920)
# define WINDOW_HEIGHT			(1080)
# define W_W					(WINDOW_WIDTH)
# define W_H					(WINDOW_HEIGHT)
# define DEFAULT_LINE_COLOR		(0xD1D1D1)
# define TEXT_COL				(0xFFFFFF)
# define TITLEBAR_COL			(0xD54545)
# define HUDBORDER_COL			(0x3d80ed)
# define HUDBG_COL				(0x2a5499)
# define HUD_HEIGHT				(265)
# define HUD_WIDTH				(195)
# define HUD_WOFFSET			(20)
# define HUDX					(WINDOW_WIDTH - 205)
# define KEYBOARD_EXTRA 		(14)
# define KEYBOARD_RESET			(15)
# define KEYBOARD_DEBUG			(2)
# define KEYBOARD_HUD			(4)
# define KEYBOARD_ROTATE_Z		(89)
# define KEYBOARD_DEROTATE_Z	(91)
# define KEYBOARD_ISO			(34)
# define KEYBOARD_QUIT			(53)
# define KEYBOARD_ZOOM			(69)
# define KEYBOARD_UNZOOM		(78)
# define KEYBOARD_LEFT			(123)
# define KEYBOARD_RIGHT			(124)
# define KEYBOARD_DOWN			(125)
# define KEYBOARD_UP			(126)
# define KEYBOARD_INC			(13)
# define KEYBOARD_DEC			(1)
# define KEYBOARD_NEXTFILE		(116)
# define KEYBOARD_PREVFILE		(121)

typedef	struct	s_point
{
	int				value;
	unsigned int	color;
}				t_point;

typedef struct	s_file
{
	char				*name;
	t_point				**points;
	unsigned int		w;
	unsigned int		h;
}				t_file;

typedef struct	s_window
{
	char				*name;
	t_point				**points;
	unsigned int		w;
	unsigned int		h;
	t_file				*file;
	void				*img;
	char				*framebuffer;
	void				*mlx_ptr;
	void				*win_ptr;
	float				z;
	float				xmove;
	float				ymove;
	float				zrot;
	unsigned int		fileidx;
	unsigned int		filecount;
	int					zoom;
	int					bpp;
	int					s_l;
	int					allocated_name;
	int					endian;
	unsigned char		effectivebpp;
	unsigned char		debug;
	unsigned char		hud;
	unsigned char		isometric;
	unsigned char		extra;
}				t_window;

typedef struct	s_coord
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_coord;

typedef struct	s_line
{
	int x;
	int y;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int start_color;
	int end_color;
}				t_line;

int				validchars(char *line);

void			free_window(t_window *win);
void			free_file(t_file *file);

void			quit_program(t_window *win);
void			init_window_values(t_window *win);
int				render_window(t_window *window);
void			draw_map(t_window *window);
void			draw_window(t_window *win);
void			keyhandler(int key, t_window *window);

void			coord_assign(t_coord *coord, t_line *line);
void			isometric(t_line *line, int z);

int				get_color(t_line *line);
void			write_pixel(t_window *window, int x, int y, int color);

#endif
