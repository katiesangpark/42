/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:11:30 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 19:11:31 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	len;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1);
	output = (char*)malloc(len + ft_strlen(s2) + 1);
	if (output == 0)
		return (0);
	ft_strcpy(output, s1);
	ft_strcpy(output + len, s2);
	return (output);
}
