/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:14:50 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 19:14:50 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_word(char const *s, unsigned int start,
			unsigned int end)
{
	char			*output;
	unsigned int	i;

	output = (char*)malloc(end - start + 2);
	if (output == 0)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (s == 0)
		return (0);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	end = start;
	while (s[end])
		end++;
	if (end != 0)
		end--;
	while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	return (copy_word(s, start, end));
}
