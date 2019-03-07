/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:24:00 by kicausse          #+#    #+#             */
/*   Updated: 2019/03/01 20:24:01 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "fdf.h"

int			parse_file(char *filename, t_file *file);

void		parse_values(char *str, t_point *data);
t_point		**create_tab(char **str, unsigned int *line_width);

int			count_file_lines(char *filename);

#endif
