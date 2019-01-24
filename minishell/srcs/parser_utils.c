/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 05:40:29 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/24 05:40:29 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ignore_chars(char **dest, char *charset)
{
	while (**dest && ft_cfind(charset, **dest) >= 0)
		++(*dest);
}

int		look_for_chars(char *dest, char *charset)
{
	unsigned int	i;

	i = 0;
	while (dest[i] && ft_cfind(charset, dest[i]) == -1)
		++i;
	return (i);
}
