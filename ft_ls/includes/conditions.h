/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 06:29:43 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/11 06:29:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONS_H
# define CONDITIONS_H
# include "args.h"

int		file_exists(char *path);
int		is_recursive(char *foldername, t_args *args);
int		is_hidden(char *filename, t_args *args);
int		is_dot(char *foldername);

#endif
