/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:24:22 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 20:24:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H
# define OPTIONS ("cspdiouxX%f")
# define FLAGS ("h;hh;l;ll")
# include "lists.h"

int			is_valid_option(char *c);
int			is_valid_flag(char *c);
int			parse_option(t_specifier **specifiers, char *str);

#endif
