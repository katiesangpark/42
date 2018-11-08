/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:58:24 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 18:58:24 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*output;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	output = (char*)malloc(ft_strlen(s) + 1);
	if (output == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		output[i] = f(s[i]);
		i++;
	}
	output[i] = 0;
	return (output);
}
