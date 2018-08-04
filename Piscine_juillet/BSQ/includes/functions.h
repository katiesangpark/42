/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:53:07 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/20 08:53:07 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFSIZE (8192)
# define CHAR_EMPTY (0)
# define CHAR_OBSTACLE (1)
# define CHAR_FULL (2)

typedef struct	s_map
{
	char	**grid;
	char	charset[3];
	int		w;
	int		h;
}				t_map;

typedef struct	s_square
{
	int		x;
	int		y;
	int		size;
}				t_square;

typedef struct	s_list
{
	struct s_list	*next;
	char			*data;
}				t_list;

t_list			*ft_create_elem(char *str);
char			*ft_list_strcpy(t_list *list);
void			ft_list_clear(t_list **begin_list);
int				ft_list_strlen(t_list *list);
int				get_map_info(char **grid, t_map *map);
int				is_in_charset(char *charset, char c);
int				is_map_valid(t_map *map, int length);
int				tab_len(char **tab);
int				resolve_bsq(char **grid);
int				ft_atoi(char *str, int end);
void			print(char *str);
void			print_error(char *str);
void			print_resolved_map(t_map *map, t_square *cube);
void			destroy_map(char *map);
void			destroy_grid(char **grid);
int				ft_strlen(char *str);
void			ft_strncpy(char *dest, char *src, int dest_len);
char			*ft_strndup(char *src, int amount);
t_list			*read_file_linked(int fd);
int				open_file(char *filename);
char			**split(char *str);

#endif
