/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:06:16 by dilaouid          #+#    #+#             */
/*   Updated: 2019/03/04 23:06:18 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "parser.h"
#include <limits.h>
#include <stdlib.h>

int			validate_resolution(void)
{
	if (WINDOW_WIDTH < 640 || WINDOW_HEIGHT < 480)
	{
		ft_printf_fd(2, "Error: defined window dimensions (%dx%d)"
						" are too small!\n", WINDOW_WIDTH, WINDOW_HEIGHT);
		return (0);
	}
	if (WINDOW_WIDTH * WINDOW_HEIGHT >= UINT_MAX)
	{
		ft_printf_fd(2, "Error: defined window dimensions (%dx%d)"
						" are too big!\n", WINDOW_WIDTH, WINDOW_HEIGHT);
		return (0);
	}
	return (1);
}

int			validate_dimensions(int width, int height)
{
	if (width <= 1 && height <= 1)
	{
		ft_printf_fd(2, "Error: file does not contain enough data!\n",
						WINDOW_WIDTH, WINDOW_HEIGHT);
		return (0);
	}
	return (1);
}

void		free_file(t_file *file)
{
	unsigned int i;

	i = 0;
	while (i < file->h)
	{
		free(file->points[i]);
		++i;
	}
	free(file->points);
}

int			read_files(t_window *win, int argc, char **argv)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (++i < argc)
	{
		if (parse_file(argv[i], &win->file[x]) == 0)
			continue ;
		if (validate_dimensions(win->file[x].w, win->file[x].h) == 0)
		{
			free_file(&win->file[x]);
			continue ;
		}
		ft_printf("Successfully parsed \"%s\", dimensions are %dx%d\n",
					win->file[x].name, win->file[x].w, win->file[x].h);
		++x;
	}
	return (x);
}

int			main(int argc, char **argv)
{
	t_window	win;

	if (argc == 1)
	{
		ft_putendl_fd("Usage: fdf <file1> <file2> ...", 2);
		return (-1);
	}
	if (validate_resolution() == 0)
		return (-1);
	ft_bzero(&win, sizeof(t_window));
	if (!(win.file = (t_file*)ft_memalloc(sizeof(t_file) * (argc - 1))))
		return (-1);
	win.filecount = read_files(&win, argc, argv);
	if (win.filecount == 0)
		ft_putendl_fd("Error: none of the given files are valid.\n", 2);
	else
		render_window(&win);
	free_window(&win);
	return (0);
}
