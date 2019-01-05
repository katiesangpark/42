/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:15:30 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:15:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INFO_2_H
# define GET_INFO_2_H
# include "args.h"
# include "file_list.h"
# include <sys/stat.h>

void	build_permission_string(char *str, int st_mode);
void	get_symlink_target(t_files *file);
void	err_file_missing(t_files *files);
int		is_readable(t_files *file, struct stat *f_stat, struct stat *l_stat);

#endif
