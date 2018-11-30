/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_hub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 02:12:33 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/30 02:12:33 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_hub.h"
#include "utils.h"
#include <stdio.h>

t_opp g_opptab[] =
{
	{'d', &int_handling},
};

void	int_handling(int value, t_specifier *spec)
{
	if (charset_match("di", spec->option))
		ft_putinbr(value);
	else if (spec->option == 'x')
		ft_print_hex2(*(unsigned int*)&value, "0123456789abcdef");
	else if (spec->option == 'X')
		ft_print_hex2(*(unsigned int*)&value, "0123456789ABCDEF");
	else if (spec->option == 'o')
		ft_putnbr_octal(*(unsigned int*)&value);
}
