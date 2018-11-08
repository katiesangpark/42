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
	if (errcode == -1)
	{
		print("tail: ");
		print(str);
		print(": No such file or directory");
	}
	else if (errcode == -2)
	{
		print("tail: illegal offset -- ");
		print(str + 2);
	}
	print("\n");
}

int		get_offset(char **argv, int argc, int *index, int *error)
{
	int	offset;

	offset = 0;
	if (argv[1][2] == '\0' && argc > 2)
	{
		offset = ft_atoi_inv(argv[2]);
		*index += 1;
		if (!is_number_valid(argv[2]))
			return (*error = -2);
		if (argc == 3)
			*index = -2;
	}
	else if (argc != 1 && argv[1][2] != '\0')
	{
		offset = ft_atoi_inv(argv[1] + 2);
		if (!is_number_valid(argv[1] + 2))
			return (*error = -2);
	}
	return (offset);
}

int		is_number_valid(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (i > 0);
}
