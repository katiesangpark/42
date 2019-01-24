/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:14:29 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:14:30 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_arguments(char *input)
{
	unsigned int	count;
	unsigned int	quote;
	unsigned int	s;
	unsigned int	e;

	s = 0;
	count = 0;
	while (++count && input[s] && !(quote = 0))
	{
		while (input[s] == '\t' || input[s] == ' ')
			++s;
		e = s;
		while (input[e] != '\t' && input[e] != ' ' && input[e] != '\0')
		{
			if (input[e] == '"' && (quote = 1) && ++e)
			{
				while (input[e] != '"' && input[e] != '\0')
					++e;
				break ;
			}
			else
				++e;
		}
		s = input[e] == '\0' ? e : e + 1 + quote;
	}
	return (count);
}

char	**parse_input(char *input)
{
	char			**args;
	unsigned int	count;
	unsigned int	quote;
	unsigned int	s;
	unsigned int	e;

	if (!(args = ft_memalloc(sizeof(char*) * count_arguments(input))))
		return (NULL);
	s = 0;
	count = 0;
	while (input[s])
	{
		quote = 0;
		while (input[s] == '\t' || input[s] == ' ')
			++s;
		e = s;
		while (input[e] != '\t' && input[e] != ' ' && input[e] != '\0')
		{
			if (input[e] == '"')
			{
				quote = 1;
				++e;
				while (input[e] != '"' && input[e] != '\0')
					++e;
				break ;
			}
			else
				++e;
		}
		args[count++] = ft_strsub(input, s + quote, e - s - quote);
		s = input[e] == '\0' ? e : e + 1 + quote;
	}
	args[count] = NULL;
	return (args);
}
