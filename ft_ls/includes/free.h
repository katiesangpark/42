/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:07:05 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 16:07:06 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "args.h"
# include "file_list.h"

void	free_file(t_files **file);
void	free_folder(t_folder **folder);
void	free_single_folder(t_folder **folder);
void	free_args(t_args **args);

#endif
