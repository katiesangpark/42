/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:24:02 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 15:24:03 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t num)
{
	while (num >= sizeof(long))
	{
		num -= sizeof(long);
		*((long*)(destination + num)) = *((long*)(source + num));
	}
	while (num >= sizeof(int))
	{
		num -= sizeof(int);
		*((int*)(destination + num)) = *((int*)(source + num));
	}
	while (num >= sizeof(short))
	{
		num -= sizeof(short);
		*((short*)(destination + num)) = *((short*)(source + num));
	}
	while (num > 0)
	{
		--num;
		((char*)destination)[num] = ((char*)source)[num];
	}
	return (destination);
}
