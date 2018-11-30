/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:29:52 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/30 02:29:52 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void			ft_putnstr(char *str, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (str[i] && i < n)
		i++;
	write(1, str, i);
}
