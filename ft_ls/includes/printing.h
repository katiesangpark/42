/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:35:44 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 10:35:45 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H
# include "file_list.h"
# include "args.h"

int		remove_nonfiles_folders(t_folder **folders);
void	print_invalid_folders(t_args *args, t_folder *folders);
void	print_folder(t_args *args, t_folder *folders);

#endif
