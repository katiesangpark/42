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
#include "constants.h"

char	*expand_variables(char *input, t_shell *shell)
{
	int		i;
	int		escape;

	i = -1;
	escape = 0;
	while (input[++i])
	{
		if (escape && !(escape = 0))
			continue ;
		if (input[i] == '\\')
		{
			escape = 1;
			ft_strcpy(input + i, input + i + 1);
			--i;
		}
		else if (input[i] == '$')
		{
			if ((input = insert_variable_value(input, i, shell)) == NULL)
				return (NULL);
			return (input);
		}
	}
	return (input);
}

char	*expand_argument(char *input, int len, int quote_type, t_shell *shell)
{
	char			*tmp;

	if ((input = ft_strsub(input, 0, len)) == NULL)
		return (NULL);
	if (quote_type == 0 || quote_type == 1)
	{
		if (input[0] == '~' && quote_type == 0)
		{
			tmp = input;
			input = ft_strins_malloc(tmp + 1,
								get_env_var("HOME", shell->env), 0);
			ft_strdel(&tmp);
			if (input == NULL)
				return (NULL);
		}
		input = expand_variables(input, shell);
	}
	return (input);
}

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
		while (input[e] && input[e] != '\t' && input[e] != ' ')
		{
			if (quote_match(input, &e, NULL))
				continue ;
			++e;
		}
		input += e;
	}
	return (count + 3);
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
				continue ;
			++e;
		}
		if ((args[count++] = expand_argument(input,
			e, quote, shell)) == NULL)
			break ;
		input += e;
	}
	args[count] = NULL;
}

char	**parse_input(char *input, t_shell *shell)
{
	char			**args;
	unsigned int	count;

	count = count_arguments(input);
	if (count == 0 || !(args = ft_memalloc(sizeof(char*) * count)))
	{
		ft_putstr_fd(SHELL_NAME": Parse error\n", 2);
		return (NULL);
	}
	fill_args(args, input, shell);
	return (args);
}
