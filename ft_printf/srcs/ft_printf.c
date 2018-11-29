/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:51:40 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/29 18:51:41 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

t_specifier		*get_specifiers(const char *format)
{
	int	i;
	t_specifier	*specifiers;

	i = 0;
	specifiers = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += parse_option(&specifiers, (char*)format + i + 1);
		}
		else
			i++;
	}
	return (specifiers);
}

int				ft_printf(const char *format, ...)
{
	char			*output;
	va_list			args;
	t_specifier		*specifiers;

	(void)output;
	specifiers = get_specifiers(format);
	va_start(args, format);
	va_end(args);
	return (0);
}
