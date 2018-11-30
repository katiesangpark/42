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

#include "functions_hub.h"
#include "ft_printf.h"
#include "libft.h"
#include "utils.h"
#include <stdarg.h>

static t_specifier	*get_specifiers(const char *format)
{
	int				i;
	t_specifier		*specifiers;

	i = 0;
	specifiers = NULL;
	while (format[i])
	{
		if (format[i] == '%')
			i += parse_option(&specifiers, (char*)format + i + 1, i);
		else
			i++;
	}
	return (specifiers);
}

static void			print_arg(va_list args, t_specifier *spec)
{
	if (charset_match("diouxX", spec->option))
		int_handling(va_arg(args, int), spec);
	else if (spec->option == 's')
		ft_putstr(va_arg(args, char *));
	else if (spec->option == 'c')
		ft_putchar(va_arg(args, int));
}

int					ft_printf(const char *format, ...)
{
	va_list			args;
	t_specifier		*specifier;
	unsigned int	idx;

	specifier = get_specifiers(format);
	va_start(args, format);
	idx = 0;
	while (specifier != NULL)
	{
		ft_putnstr((char*)format + idx, specifier->idx - idx);
		idx += specifier->idx - idx + specifier->len;
		print_arg(args, specifier);
		specifier = specifier->next;
	}
	ft_putstr((char*)format + idx);
	va_end(args);
	spec_lst_clear(specifier);
	return (0);
}
