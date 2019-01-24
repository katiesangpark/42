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

int		look_for_char(char *dest, char c)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0' && dest[i] != c)
		++i;
	return (i);
}

void	ignore_chars(char **dest, char *charset)
{
	while (**dest != '\0' && ft_cfind(charset, **dest) >= 0)
		++(*dest);
}

int		quote_match(char *input, unsigned int *e, unsigned int *quote)
{
	if (input[*e] == '"')
	{
		*quote = 1;
		*e += look_for_char(input + *e + 1, '"');
		if (input[*e] != '\0')
			*e += 1;
		return (1);
	}
	if (input[*e] == '\'')
	{
		*quote = 1;
		*e += look_for_char(input + *e + 1, '\'');
		if (input[*e] != '\0')
			*e += 1;
		return (1);
	}
	return (0);
}
