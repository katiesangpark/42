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
#include "shell.h"

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
			if (quote_match(input, &e, &quote))
				break ;
			++e;
		}
		input += *(input + e) == '\0' ? e : e + 1 + !!quote;
	}
	return (count);
}

char	*expand_argument(char *input, int len, int quote_type, t_shell *shell)
{
	char			*tmp;

	if ((input = ft_strsub(input, 0, len)) == NULL)
		return (NULL);
	if (quote_type == 0)
	{
		if (input[0] == '~')
		{
			tmp = input;
			input = ft_strins_malloc(tmp + 1,
								get_env_var("HOME", shell->env), 0);
			ft_strdel(&tmp);
			if (input == NULL)
				return (NULL);
		}
	}
	return (input);
}

void	fill_args(char **args, char *input, t_shell *shell)
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
			if (quote_match(input, &e, &quote))
				break ;
			++e;
		}
		if ((args[count++] = expand_argument(input + !!quote,
			e - !!quote, quote, shell)) == NULL)
			break ;
		input += *(input + e) == '\0' ? e : e + 1 + !!quote;
	}
	args[count] = NULL;
}

char	**parse_input(char *input, t_shell *shell)
{
	char			**args;

	if (!(args = ft_memalloc(sizeof(char*) * count_arguments(input))))
		return (NULL);
	fill_args(args, input, shell);
	return (args);
}
