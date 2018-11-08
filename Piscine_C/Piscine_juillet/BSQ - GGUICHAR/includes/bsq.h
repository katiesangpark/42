/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:22:54 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 20:09:11 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_bsq
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
}				t_bsq;

typedef struct	s_map
{
	char			*file_name;
	char			empty;
	char			obstacle;
	char			full;
	unsigned int	width;
	unsigned int	height;
	struct s_bsq	best;
}				t_map;

typedef struct	s_bufs
{
	char			*chars;
	unsigned int	*ints;
	unsigned int	*last_ints;
}				t_bufs;

typedef struct	s_print
{
	char			*buffer;
	char			*square;
	int				size;
	unsigned int	current_y;
}				t_print;

unsigned int	atoi_map(char *header, int size);

int				check_map_chars(char *ptr);

int				fill_map_chars(char *ptr, t_map *map);

int				read_map(t_map *map);

void			print_bsq(t_map *map);

void			swap_buf(unsigned int **buf, unsigned int **last_buf);

void			write_case_val(unsigned int *buf, unsigned int *last_buf
				, int index);

char			*save_stdin_as_file(void);

int				process_file(char *file_name, int index, int argc);

#endif
