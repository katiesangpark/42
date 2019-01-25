/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 07:00:34 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 07:00:34 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "parsing.h"
#include "libft.h"

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
