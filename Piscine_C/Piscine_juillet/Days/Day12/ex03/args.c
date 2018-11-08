/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:03:13 by kicausse          #+#    #+#             */
/*   Updated: 2018/07/11 00:03:14 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error_message(int errcode, char *str)
{
	if (!errcode)
		return ;
	if (errcode < 0)
	{
		print("hexdump: ");
		print(str);
		print(": No such file or directory");
		print("\n");
	}
	if (errcode == -1)
	{
		print("hexdump: ");
		print(str);
		print(": Bad file descriptor");
		print("\n");
	}
}

int		get_option(int argc, char **argv, int *index)
{
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "-C") == 0)
	{
		*index += 1;
		return (1);
	}
	return (0);
}
