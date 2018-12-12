/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 04:13:43 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/07 04:13:44 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

char	*build_prefix(char *prev_prefix, char *curr_folder)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(prev_prefix) + ft_strlen(curr_folder) + 2);
	if (tmp == NULL)
		return (NULL);
	ft_strcat(tmp, prev_prefix);
	ft_strcat(tmp, curr_folder);
	if (curr_folder[ft_strlen(curr_folder) - 1] != '/')
		ft_strcat(tmp, "/");
	return (tmp);
}
