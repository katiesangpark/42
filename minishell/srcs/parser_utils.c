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
#include "shell.h"

int		look_for_char(char *dest, char c)
{
	unsigned int	i;
	unsigned int	escape;

	i = 0;
	escape = 0;
	while (dest[i] != '\0')
	{
		if (escape && !(escape = 0))
		{
			++i;
			continue ;
		}
		if (dest[i] == '\\')
		{
			escape = 1;
			++i;
			continue ;
		}
		if (dest[i] == c)
			return (i);
		++i;
	}
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
		if (quote != NULL && (*quote = 1))
			ft_strcut(input, *e, *e + 1);
		*e += look_for_char(input + *e + (quote == NULL), '"');
		if (input[*e] != '\0' && quote != NULL)
			ft_strcut(input, *e, *e + 1);
		if (quote == NULL)
			*e += (input[*e] == '\0' ? 1 : 2);
		return (1);
	}
	if (input[*e] == '\'')
	{
		if (quote != NULL && (*quote = 2))
			ft_strcut(input, *e, *e + 1);
		*e += look_for_char(input + *e + (quote == NULL), '\'');
		if (input[*e] != '\0' && quote != NULL)
			ft_strcut(input, *e, *e + 1);
		if (quote == NULL)
			*e += (input[*e] == '\0' ? 1 : 2);
		return (1);
	}
	return (0);
}
