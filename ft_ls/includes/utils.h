/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 06:43:23 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 06:43:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "args.h"

char	*build_prefix(char *prev_prefix, char *curr_folder);
int		exists(char *path);
int		is_dir(t_args *args, char *path);
char*	is_dir2(char *path);

#endif
