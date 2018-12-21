/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:02:04 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:02:04 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_list.h"
#include "conditions.h"

t_folder	*get_last_folderfile(t_folder *files)
{
	t_folder	*end;

	end = 0;
	while (files != 0)
	{
		if (!files->is_dir)
		{
			end = files;
		}
		files = files->next;
	}
	return (end);
}
