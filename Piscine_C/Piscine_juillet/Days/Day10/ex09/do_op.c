/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 01:08:15 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/08 01:08:20 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "ft_opp.h"

void	ft_usage(int a, int b)
{
	unsigned int i;
	unsigned int len;

	(void)a;
	(void)b;
	ft_putstr("error : only [ ");
	i = 0;
	len = sizeof(g_opptab) / sizeof(g_opptab[0]) - 1;
	while (i < len)
	{
		ft_putstr(g_opptab[i].operator);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("] are accepted.");
}

void	do_op(int n1, char *operator, int n2)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = sizeof(g_opptab) / sizeof(g_opptab[0]) - 1;
	while (i < len)
	{
		if (ft_strcmp(operator, g_opptab[i].operator) == 0)
		{
			g_opptab[i].function(n1, n2);
			return ;
		}
		i++;
	}
	g_opptab[i].function(n1, n2);
}

int		main(int argc, char **argv)
{
	int		n1;
	int		n2;

	if (argc != 4)
		return (0);
	n1 = ft_atoi(argv[1]);
	n2 = ft_atoi(argv[3]);
	do_op(n1, argv[2], n2);
	ft_putchar('\n');
	return (0);
}
