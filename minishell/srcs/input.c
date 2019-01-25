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

#include <unistd.h>
#include "libft.h"
#include "constants.h"
#include "utils.h"

void	read_input(t_shell *shell)
{
	int		offset;
	char	*buf;

	buf = shell->buf;
	ft_bzero(buf, BUF_SIZE + 1);
	offset = 0;
	read(0, buf, 1);
	while (buf[offset] != '\n' && offset < BUF_SIZE)
	{
		offset++;
		read(0, buf + offset, 1);
	}
	buf[offset] = '\0';
	log_input(shell);
}
