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
#include "parsing.h"

int		count_arguments(char *input)
{
	unsigned int	count;
	unsigned int	quote;
	unsigned int	e;

	count = 0;
	while (++count && *input && !(quote = 0))
	{
		ignore_chars(&input, "\t ");
		if (*input == '\0' || (e = 0))
			break ;
		e = 0;
		while (input[e] && input[e] != '\t' && input[e] != ' ')
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
		input += *(input + e) == '\0' ? e : e + 1 + quote;
	}
	return (count);
}

void	fill_args(char **args, char *input)
{
	unsigned int	count;
	unsigned int	quote;
	unsigned int	e;

	count = 0;
	while (*input && !(quote = 0))
	{
		ignore_chars(&input, "\t ");
		if (*input == '\0' || (e = 0))
			break ;
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
		args[count++] = ft_strsub(input, 0, e - quote);
		input += *(input + e) == '\0' ? e : e + 1 + quote;
	}
	args[count] = NULL;
}

char	**parse_input(char *input)
{
	char			**args;

	if (!(args = ft_memalloc(sizeof(char*) * count_arguments(input))))
		return (NULL);
	fill_args(args, input);
	return (args);
}
