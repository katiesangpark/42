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
#include "sort_alphabetical.h"
#include "sort_access_time.h"

void	sort_folders(t_args *args, t_folder **folders)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_access_time(folders);
	else
		sort_alphabetical(folders);
	if (args->flags & FLAG_REVERSE)
		folders_reverse(folders);
}

void	sort_files(t_args *args, t_files **files)
{
	if (args->flags & FLAG_NON_SORT)
		return ;
	if (args->flags & FLAG_TIME_SORT)
		sort_access_time_files(files);
	else
		sort_alphabetical_files(files);
	if (args->flags & FLAG_REVERSE)
		files_reverse(files);
}
