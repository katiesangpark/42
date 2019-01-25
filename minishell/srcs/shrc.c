/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 07:55:25 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 07:55:25 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "shell.h"
#include "libft.h"
#include "commands.h"
#include "constants.h"
#include "parsing.h"

void	exec_shrc_command(t_shell *shell, char *cmd)
{
	char	**args;

	ft_strcpy(shell->buf, cmd);
	if ((args = parse_input(shell->buf, shell)) == NULL)
		return ;
	exec_command(shell, args);
	ft_free_tab(args);
}

void	exec_shrc(t_shell *shell)
{
	int		fd;
	char	*buf;

	if (shell->no_shrc)
		return ;
	fd = open(SHRC_FILE, O_RDWR | O_CREAT | O_APPEND, 448);
	if (fd < 0)
	{
		ft_putstr_fd(SHELL_NAME": error: could not read shrc file "SHRC_FILE
		"\n", 2);
		return ;
	}
	while (get_next_line(fd, &buf) == 1)
	{
		exec_shrc_command(shell, buf);
		ft_strdel(&buf);
	}
	close(fd);
}
