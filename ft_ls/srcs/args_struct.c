/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 06:30:25 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 06:30:25 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "args_struct.h"

t_args	*new_args(void)
{
	t_args	*new;

	if ((new = (t_args*)ft_memalloc(sizeof(t_args))) == NULL)
		return (NULL);
	return (new);
}

void	free_file(t_files **file)
{
	if (file == NULL || *file == NULL)
		return ;
	free_file(&(*file)->next);
	ft_strdel(&(*file)->name);
	ft_strdel(&(*file)->prefix);
	ft_strdel(&(*file)->fullpath);
	ft_memdel((void**)file);
	*file = NULL;
}

void	free_folder(t_folder **folder)
{
	if (folder == NULL || *folder == NULL)
		return ;
	free_folder(&(*folder)->subfolders);
	free_folder(&(*folder)->next);
	free_file(&((*folder)->files));
	ft_strdel(&(*folder)->name);
	ft_strdel(&(*folder)->prefix);
	ft_strdel(&(*folder)->fullpath);
	ft_memdel((void**)folder);
}

void	free_args(t_args **args)
{
	free_folder(&(*args)->search_folder);
	ft_memdel((void*)args);
}
