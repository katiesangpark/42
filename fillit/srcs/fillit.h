/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:17:04 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/25 07:17:05 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define CONST_BUF_SIZE (21)
# define DEFAULT_POS (0)
# define MAX_TETR_NBR (26)
# define CHARSET ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

typedef struct	s_block
{
	struct s_block	*next;
	int				x;
	int				y;
	int				w;
	int				h;
	int				data;
}				t_block;

int				ft_sqrt(int nb);

void			print_map(t_block *blocks, const int map_size);
void			print_map_slow(t_block *blocks, const int map_size);
char			get_char_from_coords(t_block *blocks, const int x, const int y);

int				read_file(char *filename, t_block **out);
int				str_to_data(char *str);
int				is_line_valid(char *line, int strict);

int				validate_block_shapes(t_block *block);
int				correct_blocks_starting_pos(t_block	*block);
int				move_bits(int nbr, int leftmost, int upmost);
void			get_block_size(t_block *block);

int				get_bit_from_coords(const int data, const int x, const int y);
int				solve(t_block *beginlist, t_block *block, const int map_size);
void			solve2(void);

t_block			*lst_new(int data);
t_block			*lst_push(t_block **begin_list, int data);
void			lst_clear(t_block *lst);
int				lst_index(const t_block *begin, t_block *elem);
int				lst_size(t_block *elem);

#endif
