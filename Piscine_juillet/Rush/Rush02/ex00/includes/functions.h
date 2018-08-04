/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:15:45 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/21 16:15:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# define BUFSIZE (2048)
# define COLLE00 (1)
# define COLLE01 (2)
# define COLLE02 (4)
# define COLLE03 (8)
# define COLLE04 (16)
# define COLLE_SQUARE (32)
# define COLLE_RECTANGLE (64)
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_tab
{
	int		max_width;
	int		length;
	char	**input;
	char	*str;
}				t_tab;

static const char g_names[][32] = {
	"colle-00",
	"colle-01",
	"colle-02",
	"colle-03",
	"colle-04",
	"carre",
	"rectangle"
};

static const char g_charset[][32] = {
	"oooo-| ",
	"/\\\\/** ",
	"AACCBB ",
	"ACACBB ",
	"ACCABB "
};

int				match(char *s1, char *s2);
int				get_colle_from_bit(int colle);
int				detect_rect(t_tab file);
int				detect_shapes(t_tab file);
int				c_find(const char s1[32], char c);
int				find_character(char *str, char c, int end);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				identify_colle(t_tab file);
int				count_bits(int colle);
int				get_colle(t_tab file, char *charset);
int				match_strings(char *s1, const char s2[32]);
char			*read_file(int fd);
char			*print_rect(char *str, int x, int y);
char			*ft_strncpy(char *dest, char *src, int dest_len);
char			*concat_strings(char *dest, char *src, int amount);
char			**split(char *str);
void			print(char *str);
void			print_colle(t_tab file, int colle);

#endif
