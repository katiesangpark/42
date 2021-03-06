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
	if (n != 0)
	{
		while (n-- != 0)
		{
			((unsigned char*)sl)[n] = 0;
		}
	}
}
