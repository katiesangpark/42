/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:20:53 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/02 15:20:54 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int offset;

	offset = 0;
	while (dest[offset] != '\0')
		offset++;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[offset + i] = src[i];
		i++;
	}
	dest[offset + i] = '\0';
	while (++i < nb)
		dest[offset + i] = '\0';
	return (dest);
}
