/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:52:35 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 14:52:36 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *sl, size_t n)
{
	while (n >= sizeof(long))
	{
		n -= sizeof(long);
		*((long*)(sl + n)) = 0;
	}
	while (n >= sizeof(int))
	{
		n -= sizeof(int);
		*((int*)(sl + n)) = 0;
	}
	while (n >= sizeof(short))
	{
		n -= sizeof(short);
		*((short*)(sl + n)) = 0;
	}
	while (n > 0)
	{
		--n;
		((char*)sl)[n] = 0;
	}
}
