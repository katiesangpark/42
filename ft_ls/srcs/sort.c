/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:48:12 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 16:48:12 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"
#include "sort_reverse.h"
#include "sort_time.h"

void	sort_folders(t_args *args, t_folder **folders)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_time(folders);
	if (args->flags & FLAG_REVERSE)
		folders_reverse(folders);
}

void	sort_files(t_args *args, t_files **files)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_time_files(files);
	if (args->flags & FLAG_REVERSE)
		files_reverse(files);
}
