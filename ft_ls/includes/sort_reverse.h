/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:22:02 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 17:22:03 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_REVERSE_H
# define SORT_REVERSE_H
# include "args.h"
# include "file_list.h"

void	folders_reverse(t_folder **begin_list);
void	files_reverse(t_files **files);

#endif
