/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:03:07 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 16:03:07 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *buffer;

	if (n != 0)
	{
		buffer = (unsigned char*)malloc(n);
		if (buffer == NULL)
			return (NULL);
		ft_memcpy(buffer, src, n);
		ft_memcpy(dest, buffer, n);
		free(buffer);
	}
	return (dest);
}
