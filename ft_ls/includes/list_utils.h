/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:03:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:03:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H
# include "file_list.h"
# include <string.h>

t_folder	*get_last_folderfile(t_folder *files);
void		print_group_with_pad(t_files *files, int reset);
void		print_owner_with_pad(t_files *files, int reset);
void		print_links_with_pad(t_files *files, int reset);
void		print_size_with_pad(t_files *files, int reset);

#endif
