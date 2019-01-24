/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:17:46 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/24 02:17:47 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <unistd.h>

void	read_input(char *buf)
{
	int		offset;

	offset = 0;
	read(0, buf, 1);
	while (buf[offset] != '\n' && offset < BUF_SIZE)
	{
		offset++;
		read(0, buf + offset, 1);
	}
	buf[offset] = '\0';
}
