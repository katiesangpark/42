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

int		get_var_end(char *var)
{
	int i;

	i = 0;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '-' || var[i] == '_'))
		++i;
	return (i);
}

char	*insert_variable_value(char *input, int i, t_shell *shell)
{
	int		var_end;
	char	*tmp;
	char	*var_value;
	char	memory;

	var_end = get_var_end(input + i + 1);
	memory = input[i + 1 + var_end];
	input[i + 1 + var_end] = '\0';
	var_value = get_env_var(input + i + 1, shell->env);
	input[i + 1 + var_end] = memory;
	ft_strcut(input, i, var_end + 1);
	tmp = input;
	input = ft_strins_malloc(input, var_value, i);
	ft_strdel(&tmp);
	return (input);
}

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
		*quote = 2;
		*e += look_for_char(input + *e + 1, '\'');
		if (input[*e] != '\0')
			*e += 1;
		return (1);
	}
	return (0);
}
