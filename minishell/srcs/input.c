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

int		read_input(t_shell *shell)
{
	unsigned int	offset;
	unsigned int	bufsize;

	bufsize = BUF_SIZE;
	ft_bzero(shell->buf, bufsize + 1);
	offset = 0;
	read(0, shell->buf, 1);
	while (shell->buf[offset] != '\n' && offset < bufsize)
	{
		if (++offset >= bufsize)
		{
			shell->buf[offset] = '\0';
			if ((shell->buf = ft_realloc(shell->buf, bufsize *= 2)) == NULL)
				return (0);
		}
		read(0, shell->buf + offset, 1);
	}
	shell->buf[offset] = '\0';
	log_input(shell);
	return (1);
}
