/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 01:26:27 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/19 01:26:28 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(size);
	if (tmp != NULL)
	{
		ft_memcpy(tmp, ptr, size);
		free(ptr);
	}
	return (tmp);
}
