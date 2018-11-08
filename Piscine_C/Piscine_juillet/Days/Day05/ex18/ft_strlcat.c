/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:24:56 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 15:24:56 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int offset;
	unsigned int srclen;

	offset = 0;
	while (dest[offset] != '\0')
		offset++;
	i = 0;
	srclen = 0;
	while (src[i] != '\0' && offset + i < size - 1)
	{
		dest[offset + i] = src[i];
		i++;
		srclen++;
	}
	dest[offset + i] = '\0';
	while (src[srclen] != '\0')
		srclen++;
	if (size < offset)
		return (srclen + size);
	return (offset + srclen);
}
