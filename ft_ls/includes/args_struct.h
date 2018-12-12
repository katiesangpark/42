/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 06:43:03 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 06:43:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_STRUCT_H
# define ARGS_STRUCT_H
# include "file_list.h"

typedef struct	s_args
{
	int			flags;
	t_folder	*search_folder;
}				t_args;

t_args			*new_args(void);
void			free_args(t_args **args);
void			free_folder(t_folder **folder);

#endif
