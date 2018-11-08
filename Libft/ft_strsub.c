/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:08:46 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 19:08:46 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	i;

	if (s == 0)
		return (0);
	output = (char*)malloc(len + 1);
	if (output == 0)
		return (0);
	i = 0;
	output[len] = 0;
	while (len--)
	{
		output[i] = s[start + i];
		i++;
	}
	return (output);
}
