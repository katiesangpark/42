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

int		is_valid_option(char *c)
{
	(void)c;
	return (1);
}

int		parse_option(t_specifier **specifiers, char *str)
{
	if (*str == '\0')
		return (0);
	(void)specifiers;
	return (1);
}
