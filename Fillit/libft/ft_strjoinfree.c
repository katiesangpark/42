/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 00:17:31 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/16 00:17:32 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *source, const char *concat)
{
	char	*tmp;

	if (source == NULL)
		tmp = ft_strdup(concat);
	else
		tmp = ft_strjoin(source, concat);
	free(source);
	return (tmp);
}
