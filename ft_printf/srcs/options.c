/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:23:22 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 20:23:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "libft.h"

const char	g_flags[FLAG_COUNT][8] = {
	"h",
	"hh",
	"l",
	"ll"
};

int			is_valid_option(char c)
{
	return (ft_strchr(OPTIONS, c) != NULL);
}

static void	ft_get_flag(char *s, t_specifier *spec)
{
	int		i;

	i = 0;
	while (i < FLAG_COUNT)
	{
		if (ft_strncmp(s, g_flags[i], ft_strlen(g_flags[i])) == 0)
		{
			spec->flag = ft_strdup(g_flags[i]);
			return ;
		}
		i++;
	}
}

int			parse_option(t_specifier **specifiers, char *str, int idx)
{
	t_specifier	*spec;

	if (*str == '\0')
		return (0);
	(void)ft_get_flag;
	spec = spec_lst_new(0, NULL, idx);
	spec->option = *str;
	spec->len = 2;
	spec->idx = idx;
	spec_lst_push(specifiers, spec);
	return (spec->len);
}
